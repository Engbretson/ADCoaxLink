/* Copyright Euresys 2014 */

#ifndef EURESYS_LOCKS_HEADER_FILE
#define EURESYS_LOCKS_HEADER_FILE

namespace EURESYS_NAMESPACE {
namespace Internal {

#if defined(linux) || defined(__linux) || defined(__linux__)

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 600
#endif
#include <pthread.h>

class ConcurrencyLock {
    public:
        ConcurrencyLock() {
            pthread_mutexattr_t attr;
            pthread_mutexattr_init(&attr);
            pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP);
            pthread_mutex_init(&mutex, &attr);
            pthread_mutexattr_destroy(&attr);
        }
        ~ConcurrencyLock() {
            pthread_mutex_destroy(&mutex);
        }
        void lock() {
            pthread_mutex_lock(&mutex);
        }
        void unlock() {
            pthread_mutex_unlock(&mutex);
        }

    private:
        pthread_mutex_t mutex;
};

#else

class ConcurrencyLock {
    public:
        ConcurrencyLock() {
            InitializeCriticalSection(&cs);
        }
        ~ConcurrencyLock() {
            DeleteCriticalSection(&cs);
        }
        void lock() {
            EnterCriticalSection(&cs);
        }
        void unlock() {
            LeaveCriticalSection(&cs);
        }

    private:
        CRITICAL_SECTION cs;
};

#endif

class AutoLock
{
public:
    AutoLock(ConcurrencyLock &lock) : lock(lock) {
        lock.lock();
    }

    ~AutoLock() {
        lock.unlock();
    }

private:
    ConcurrencyLock &lock;
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
