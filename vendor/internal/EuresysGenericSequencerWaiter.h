/* Copyright Euresys 2015 */

#ifndef EGENERICSEQUENCERWAITER_IMPL_HEADER_FILE
#define EGENERICSEQUENCERWAITER_IMPL_HEADER_FILE

namespace EURESYS_NAMESPACE {
namespace Internal {

#if defined(linux) || defined(__linux) || defined(__linux__)

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 600
#endif

#include <pthread.h>
#include <errno.h>
#include <string.h>

class GenericSequencerWaiterOS {
    public:
        typedef struct timespec Time;

        GenericSequencerWaiterOS()
        : clk_id(CLOCK_MONOTONIC)
        {
            if (pthread_mutex_init(&mutex, NULL)) {
                throw client_error("GenericSequencerWaiterOS could not initialize mutex");
            }
            pthread_condattr_t condattr;
            if (pthread_condattr_init(&condattr)) {
                pthread_mutex_destroy(&mutex);
                throw client_error("GenericSequencerWaiterOS could not initialize condition variable attributes");
            }
            if (pthread_condattr_setclock(&condattr, clk_id)) {
                pthread_condattr_destroy(&condattr);
                pthread_mutex_destroy(&mutex);
                throw client_error("GenericSequencerWaiterOS could not set clock id");
            }
            if (pthread_cond_init(&condition, &condattr)) {
                pthread_condattr_destroy(&condattr);
                pthread_mutex_destroy(&mutex);
                throw client_error("GenericSequencerWaiterOS could not initialize condition variable");
            }
            if (pthread_condattr_destroy(&condattr)) {
                pthread_cond_destroy(&condition);
                pthread_mutex_destroy(&mutex);
                throw client_error("GenericSequencerWaiterOS could not destroy condition variable attributes");
            }
        }
        ~GenericSequencerWaiterOS() {
            pthread_cond_destroy(&condition);
            pthread_mutex_destroy(&mutex);
        }
        void lock() {
            pthread_mutex_lock(&mutex);
        }
        void unlock() {
            pthread_mutex_unlock(&mutex);
        }
        void signalCondition() {
            pthread_cond_signal(&condition);
        }
        bool waitCondition(Time *until, bool *timeout) {
            int res;
            if (!until->tv_sec && !until->tv_nsec) {
                res = pthread_cond_wait(&condition, &mutex);
            } else {
                res = pthread_cond_timedwait(&condition, &mutex, until);
            }
            *timeout = (res == ETIMEDOUT);
            return (res == 0);
        }
        void getTime(Time *t) {
            if (clock_gettime(clk_id, t)) {
                throw client_error("GenericSequencerWaiterOS could not get current time");
            }
        }
        void addMs(Time *t, uint64_t ms) {
            uint64_t tms = ms + ((uint64_t)t->tv_sec * 1000 + t->tv_nsec / 1000000);
            t->tv_sec = tms / 1000;
            t->tv_nsec = (tms % 1000) * 1000000;
        }
        void setInfinite(Time *t) {
            t->tv_sec = 0;
            t->tv_nsec = 0;
        }
    private:
        pthread_mutex_t mutex;
        pthread_cond_t condition;
        clockid_t clk_id;
};

#else

#include <Windows.h>

#if !defined(WINVER) && !defined(_WIN32_WINNT)
#error Unknown target Windows version, please define WINVER or _WIN32_WINNT
#elif defined(WINVER) && WINVER < 0x0600
#error Target Windows version must be at least 0x0600 (Vista), please check your WINVER definition (we recommend Windows SDK 7.1)
#elif defined(_WIN32_WINNT) && _WIN32_WINNT < 0x0600
#error Target Windows version must be at least 0x0600 (Vista), please check your _WIN32_WINNT definition (we recommend Windows SDK 7.1)
#endif

class GenericSequencerWaiterOS {
    public:
        typedef struct {
            ULONGLONG tick;
            DWORD ms;
        } Time;

        GenericSequencerWaiterOS()
        {
            InitializeCriticalSection(&mutex);
            InitializeConditionVariable(&condition);
        }
        ~GenericSequencerWaiterOS() {
            // DeleteConditionVariable(&condition);
            DeleteCriticalSection(&mutex);
        }
        void lock() {
            EnterCriticalSection(&mutex);
        }
        void unlock() {
            LeaveCriticalSection(&mutex);
        }
        void signalCondition() {
            WakeConditionVariable(&condition);
        }
        bool waitCondition(Time *until, bool *timeout) {
            if (until->ms == 0) {
                *timeout = true;
                return false;
            }
            bool success = (0 != SleepConditionVariableCS(&condition, &mutex, until->ms));
            ULONGLONG now = GetTickCount64();
            ULONGLONG end = until->tick + until->ms;
            until->tick = now;
            until->ms = (now < end) ? ((DWORD)(end - now)) : 0;
            if (!success) {
                DWORD last = GetLastError();
                *timeout = (last == ERROR_TIMEOUT);
            } else {
                *timeout = false;
            }
            return success;
        }
        void getTime(Time *t) {
            t->tick = GetTickCount64();
            t->ms = 0;
        }
        void addMs(Time *t, uint64_t ms) {
            if ((uint64_t)t->ms + ms > (uint64_t)INFINITE) {
                throw client_error("GenericSequencerWaiterOS could not set time interval (too large)");
            }
            t->ms += (DWORD)ms;
        }
        void setInfinite(Time *t) {
            t->tick = GetTickCount64();
            t->ms = INFINITE;
        }
    private:
        CRITICAL_SECTION mutex;
        CONDITION_VARIABLE condition;
};

#endif

class GenericSequencerWaiter: private GenericSequencerWaiterOS {
    public:
        enum WaitResult {
            TIMEOUT,
            NOTIFIED,
            CANCELLED
        };

        GenericSequencerWaiter()
        : filter(0)
        , cancelFlag(false)
        , notifyFlag(false)
        {
        }
        bool alloc(size_t newFilter, uint64_t timeout) {
            Time t;
            if (timeout != GENTL_INFINITE) {
                getTime(&t);
                addMs(&t, timeout);
            } else {
                setInfinite(&t);
            }
            bool allocated = false;
            lock();
            if (filter == 0) {
                filter = newFilter;
                cancelFlag = false;
                notifyFlag = false;
                until = t;
                allocated = true;
            }
            unlock();
            return allocated;
        }
        void release() {
            lock();
            filter = 0;
            cancelFlag = false;
            notifyFlag = false;
            unlock();
        }
        WaitResult wait() {
            WaitResult res;
            bool failure = false;
            bool timeout = false;
            lock();
            while (!cancelFlag && !notifyFlag && waitCondition(&until, &timeout)) {
            }
            if (cancelFlag) {
                res = CANCELLED;
            } else if (notifyFlag) {
                res = NOTIFIED;
            } else if (timeout) {
                res = TIMEOUT;
            } else {
                failure = true;
            }
            /* auto reset */
            cancelFlag = false;
            notifyFlag = false;
            unlock();
            if (failure) {
                throw client_error("GenericSequencerWaiter condition wait failed");
            }
            return res;
        }
        bool cancel(size_t f) {
            bool res = false;
            lock();
            if (filter & f) {
                res = true;
                cancelFlag = true;
            }
            unlock();
            if (res) signalCondition();
            return res;
        }
        bool notify(size_t f) {
            bool res = false;
            lock();
            if (filter & f) {
                res = true;
                notifyFlag = true;
            }
            unlock();
            if (res) signalCondition();
            return res;
        }
    private:
        size_t filter;
        bool cancelFlag;
        bool notifyFlag;
        Time until;
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
