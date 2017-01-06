/* Copyright Euresys 2016 */

#ifndef EURESYS_TRACE_HEADER_FILE
#define EURESYS_TRACE_HEADER_FILE

namespace EURESYS_NAMESPACE {

template <typename T> struct WeightOf {
    enum {
        value = (sizeof(T) + sizeof(int) - 1) / sizeof(int)
    };
};

template <typename T> struct ETraceIntArg {
    typedef T arg_t;
    enum { weight = WeightOf<arg_t>::value };
    static void toArg(PEGrabberTrace EGrabberTrace, char LEVEL, const arg_t &a, int *i, char *f) {
        i[0] = a & 0xFFFFFFFF;
        f[0] = 'i';
        if (2 <= weight) {
            i[1] = (((long long int )a) >> 32) & 0xFFFFFFFF;
            f[1] = '+';
        }
    }
};

struct ETraceStrArg {
    typedef std::string arg_t;
    enum { weight = 1 };
    static void toArg(PEGrabberTrace EGrabberTrace, char LEVEL, const arg_t &_a, int *i, char *f) {
        int a = EGrabberTrace(LEVEL, 0, _a.c_str(), 0);
        i[0] = a & 0xFFFFFFFF;
        f[0] = 's';
    }
};

struct ETracePtrArg {
    typedef void *arg_t;
    enum { weight = WeightOf<uintptr_t>::value };
    static void toArg(PEGrabberTrace EGrabberTrace, char LEVEL, const arg_t &_a, int *i, char *f) {
        uintptr_t a = reinterpret_cast<uintptr_t>(_a);
        i[0] = a & 0xFFFFFFFF;
        f[0] = 'i';
        if (2 <= weight) {
            i[1] = (((long long int )a) >> 32) & 0xFFFFFFFF;
            f[1] = '+';
        }
    }
};

template <char Ti> struct ETraceArg {};
template <> struct ETraceArg<'S'> { typedef ETraceIntArg<size_t> info_t; };
template <> struct ETraceArg<'i'> { typedef ETraceIntArg<int> info_t; };
template <> struct ETraceArg<'X'> { typedef ETraceIntArg<uint64_t> info_t; };
template <> struct ETraceArg<'x'> { typedef ETraceIntArg<uint32_t> info_t; };
template <> struct ETraceArg<'s'> { typedef ETraceStrArg info_t; };
template <> struct ETraceArg<'p'> { typedef ETracePtrArg info_t; };
template <> struct ETraceArg<'U'> { typedef ETraceIntArg<uint64_t> info_t; };
template <> struct ETraceArg<'u'> { typedef ETraceIntArg<uint32_t> info_t; };

template <char Ti1> struct ETArgs1 {
    int a[ETraceArg<Ti1>::info_t::weight];
    char f[ETraceArg<Ti1>::info_t::weight + 1];
    ETArgs1(PEGrabberTrace EGrabberTrace, char LEVEL, const typename ETraceArg<Ti1>::info_t::arg_t &arg1)
    {
        ETraceArg<Ti1>::info_t::toArg(EGrabberTrace, LEVEL, arg1, &a[0], &f[0]);
        f[ETraceArg<Ti1>::info_t::weight] = 0;
    }
    int *address() { return &a[0]; }
    char *format() { return &f[0]; }
};

template <char Ti1, char Ti2> struct ETArgs2 {
    int a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight];
    char f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + 1];
    ETArgs2(PEGrabberTrace EGrabberTrace, char LEVEL, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2)
    {
        ETraceArg<Ti1>::info_t::toArg(EGrabberTrace, LEVEL, arg1, &a[0], &f[0]);
        ETraceArg<Ti2>::info_t::toArg(EGrabberTrace, LEVEL, arg2, &a[ETraceArg<Ti1>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight]);
        f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight] = 0;
    }
    int *address() { return &a[0]; }
    char *format() { return &f[0]; }
};

template <char Ti1, char Ti2, char Ti3> struct ETArgs3 {
    int a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight];
    char f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight + 1];
    ETArgs3(PEGrabberTrace EGrabberTrace, char LEVEL, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3)
    {
        ETraceArg<Ti1>::info_t::toArg(EGrabberTrace, LEVEL, arg1, &a[0], &f[0]);
        ETraceArg<Ti2>::info_t::toArg(EGrabberTrace, LEVEL, arg2, &a[ETraceArg<Ti1>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight]);
        ETraceArg<Ti3>::info_t::toArg(EGrabberTrace, LEVEL, arg3, &a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight]);
        f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight] = 0;
    }
    int *address() { return &a[0]; }
    char *format() { return &f[0]; }
};

template <char Ti1, char Ti2, char Ti3, char Ti4> struct ETArgs4 {
    int a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight + ETraceArg<Ti4>::info_t::weight];
    char f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight + ETraceArg<Ti4>::info_t::weight + 1];
    ETArgs4(PEGrabberTrace EGrabberTrace, char LEVEL, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3, const typename ETraceArg<Ti4>::info_t::arg_t &arg4)
    {
        ETraceArg<Ti1>::info_t::toArg(EGrabberTrace, LEVEL, arg1, &a[0], &f[0]);
        ETraceArg<Ti2>::info_t::toArg(EGrabberTrace, LEVEL, arg2, &a[ETraceArg<Ti1>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight]);
        ETraceArg<Ti3>::info_t::toArg(EGrabberTrace, LEVEL, arg3, &a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight]);
        ETraceArg<Ti4>::info_t::toArg(EGrabberTrace, LEVEL, arg4, &a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight]);
        f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight + ETraceArg<Ti4>::info_t::weight] = 0;
    }
    int *address() { return &a[0]; }
    char *format() { return &f[0]; }
};

class ETraceContext {
    public:
        ETraceContext(PEGrabberTrace EGrabberTrace)
        : EGrabberTrace(EGrabberTrace)
        {}
        template <unsigned long long FID> void checkFID();
        template <unsigned long long FID> void checkLEVEL();
        template <size_t WEIGHT> void checkWEIGHT();
        template <char LEVEL, unsigned long long FID> void hTrace(const char *format);
        template <char LEVEL, unsigned long long FID, char Ti1> void hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1);
        template <char LEVEL, unsigned long long FID, char Ti1, char Ti2> void hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2);
        template <char LEVEL, unsigned long long FID, char Ti1, char Ti2, char Ti3> void hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3);
        template <char LEVEL, unsigned long long FID, char Ti1, char Ti2, char Ti3, char Ti4> void hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3, const typename ETraceArg<Ti4>::info_t::arg_t &arg4);
    private:
        PEGrabberTrace EGrabberTrace;
};

template <unsigned long long FID> inline void ETraceContext::checkFID() {}
template <> inline void ETraceContext::checkFID<0>(); // not implemented

template <> inline void ETraceContext::checkLEVEL<'C'>() {}
template <> inline void ETraceContext::checkLEVEL<'E'>() {}
template <> inline void ETraceContext::checkLEVEL<'W'>() {}
template <> inline void ETraceContext::checkLEVEL<'N'>() {}
template <> inline void ETraceContext::checkLEVEL<'I'>() {}
template <> inline void ETraceContext::checkLEVEL<'D'>() {}
template <> inline void ETraceContext::checkLEVEL<'V'>() {}

template <> inline void ETraceContext::checkWEIGHT<1>() {}
template <> inline void ETraceContext::checkWEIGHT<2>() {}
template <> inline void ETraceContext::checkWEIGHT<3>() {}
template <> inline void ETraceContext::checkWEIGHT<4>() {}
template <> inline void ETraceContext::checkWEIGHT<5>() {}

template <char LEVEL, unsigned long long FID> inline void ETraceContext::hTrace(const char *format) {
    checkLEVEL<LEVEL>();
    checkFID<FID>();
    EGrabberTrace(LEVEL, FID, "", 0);
}
template <char LEVEL, unsigned long long FID, char Ti1> inline void ETraceContext::hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1) {
    checkLEVEL<LEVEL>();
    checkFID<FID>();
    checkWEIGHT<ETraceArg<Ti1>::info_t::weight>();
    ETArgs1<Ti1> args(EGrabberTrace, LEVEL, arg1);
    EGrabberTrace(LEVEL, FID, args.format(), args.address());
}
template <char LEVEL, unsigned long long FID, char Ti1, char Ti2> inline void ETraceContext::hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2) {
    checkLEVEL<LEVEL>();
    checkFID<FID>();
    checkWEIGHT<ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight>();
    ETArgs2<Ti1, Ti2> args(EGrabberTrace, LEVEL, arg1, arg2);
    EGrabberTrace(LEVEL, FID, args.format(), args.address());
}
template <char LEVEL, unsigned long long FID, char Ti1, char Ti2, char Ti3> inline void ETraceContext::hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3) {
    checkLEVEL<LEVEL>();
    checkFID<FID>();
    checkWEIGHT<ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight>();
    ETArgs3<Ti1, Ti2, Ti3> args(EGrabberTrace, LEVEL, arg1, arg2, arg3);
    EGrabberTrace(LEVEL, FID, args.format(), args.address());
}
template <char LEVEL, unsigned long long FID, char Ti1, char Ti2, char Ti3, char Ti4> inline void ETraceContext::hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3, const typename ETraceArg<Ti4>::info_t::arg_t &arg4) {
    checkLEVEL<LEVEL>();
    checkFID<FID>();
    checkWEIGHT<ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight + ETraceArg<Ti4>::info_t::weight>();
    ETArgs4<Ti1, Ti2, Ti3, Ti4> args(EGrabberTrace, LEVEL, arg1, arg2, arg3, arg4);
    EGrabberTrace(LEVEL, FID, args.format(), args.address());
}

}

#endif
