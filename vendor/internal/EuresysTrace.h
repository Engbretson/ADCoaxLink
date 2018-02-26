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
    static void toArg(PEGrabberTrace EGrabberTrace, char level, const arg_t &a, int *i, char *f) {
        i[0] = static_cast<int>(a & 0xFFFFFFFF);
        f[0] = 'i';
        if (2 <= weight) {
            i[1] = static_cast<int>((static_cast<long long int>(a) >> 32) & 0xFFFFFFFF);
            f[1] = '+';
        }
    }
};

struct ETraceStrArg {
    typedef std::string arg_t;
    enum { weight = 1 };
    static void toArg(PEGrabberTrace EGrabberTrace, char level, const arg_t &_a, int *i, char *f) {
        int a = EGrabberTrace(level, 0, _a.c_str(), 0);
        i[0] = static_cast<int>(a & 0xFFFFFFFF);
        f[0] = 's';
    }
};

struct ETracePtrArg {
    typedef void *arg_t;
    enum { weight = WeightOf<arg_t>::value };
    static void toArg(PEGrabberTrace EGrabberTrace, char level, const arg_t &_a, int *i, char *f) {
        unsigned long long a = reinterpret_cast<unsigned long long>(_a);
        i[0] = static_cast<int>(a & 0xFFFFFFFF);
        f[0] = 'i';
        if (2 <= weight) {
            i[1] = static_cast<int>((a >> 32) & 0xFFFFFFFF);
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
    ETArgs1(PEGrabberTrace EGrabberTrace, char level, const typename ETraceArg<Ti1>::info_t::arg_t &arg1)
    {
        ETraceArg<Ti1>::info_t::toArg(EGrabberTrace, level, arg1, &a[0], &f[0]);
        f[ETraceArg<Ti1>::info_t::weight] = 0;
    }
    int *address() { return &a[0]; }
    char *format() { return &f[0]; }
};

template <char Ti1, char Ti2> struct ETArgs2 {
    int a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight];
    char f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + 1];
    ETArgs2(PEGrabberTrace EGrabberTrace, char level, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2)
    {
        ETraceArg<Ti1>::info_t::toArg(EGrabberTrace, level, arg1, &a[0], &f[0]);
        ETraceArg<Ti2>::info_t::toArg(EGrabberTrace, level, arg2, &a[ETraceArg<Ti1>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight]);
        f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight] = 0;
    }
    int *address() { return &a[0]; }
    char *format() { return &f[0]; }
};

template <char Ti1, char Ti2, char Ti3> struct ETArgs3 {
    int a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight];
    char f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight + 1];
    ETArgs3(PEGrabberTrace EGrabberTrace, char level, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3)
    {
        ETraceArg<Ti1>::info_t::toArg(EGrabberTrace, level, arg1, &a[0], &f[0]);
        ETraceArg<Ti2>::info_t::toArg(EGrabberTrace, level, arg2, &a[ETraceArg<Ti1>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight]);
        ETraceArg<Ti3>::info_t::toArg(EGrabberTrace, level, arg3, &a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight]);
        f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight] = 0;
    }
    int *address() { return &a[0]; }
    char *format() { return &f[0]; }
};

template <char Ti1, char Ti2, char Ti3, char Ti4> struct ETArgs4 {
    int a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight + ETraceArg<Ti4>::info_t::weight];
    char f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight + ETraceArg<Ti4>::info_t::weight + 1];
    ETArgs4(PEGrabberTrace EGrabberTrace, char level, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3, const typename ETraceArg<Ti4>::info_t::arg_t &arg4)
    {
        ETraceArg<Ti1>::info_t::toArg(EGrabberTrace, level, arg1, &a[0], &f[0]);
        ETraceArg<Ti2>::info_t::toArg(EGrabberTrace, level, arg2, &a[ETraceArg<Ti1>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight]);
        ETraceArg<Ti3>::info_t::toArg(EGrabberTrace, level, arg3, &a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight]);
        ETraceArg<Ti4>::info_t::toArg(EGrabberTrace, level, arg4, &a[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight], &f[ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight]);
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
        template <unsigned long long Fid> void checkFid();
        template <char TLevel> void checkTLevel();
        template <size_t TWeight> void checkTWeight();
        template <char TLevel, unsigned long long Fid> void hTrace(const char *format);
        template <char TLevel, unsigned long long Fid, char Ti1> void hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1);
        template <char TLevel, unsigned long long Fid, char Ti1, char Ti2> void hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2);
        template <char TLevel, unsigned long long Fid, char Ti1, char Ti2, char Ti3> void hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3);
        template <char TLevel, unsigned long long Fid, char Ti1, char Ti2, char Ti3, char Ti4> void hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3, const typename ETraceArg<Ti4>::info_t::arg_t &arg4);
    private:
        PEGrabberTrace EGrabberTrace;
};

template <unsigned long long Fid> inline void ETraceContext::checkFid() {}
template <> inline void ETraceContext::checkFid<0>(); // not implemented

template <> inline void ETraceContext::checkTLevel<'C'>() {}
template <> inline void ETraceContext::checkTLevel<'E'>() {}
template <> inline void ETraceContext::checkTLevel<'W'>() {}
template <> inline void ETraceContext::checkTLevel<'N'>() {}
template <> inline void ETraceContext::checkTLevel<'I'>() {}
template <> inline void ETraceContext::checkTLevel<'D'>() {}
template <> inline void ETraceContext::checkTLevel<'V'>() {}

template <> inline void ETraceContext::checkTWeight<1>() {}
template <> inline void ETraceContext::checkTWeight<2>() {}
template <> inline void ETraceContext::checkTWeight<3>() {}
template <> inline void ETraceContext::checkTWeight<4>() {}
template <> inline void ETraceContext::checkTWeight<5>() {}

template <char TLevel, unsigned long long Fid> inline void ETraceContext::hTrace(const char *format) {
    checkTLevel<TLevel>();
    checkFid<Fid>();
    EGrabberTrace(TLevel, Fid, "", 0);
}
template <char TLevel, unsigned long long Fid, char Ti1> inline void ETraceContext::hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1) {
    checkTLevel<TLevel>();
    checkFid<Fid>();
    checkTWeight<ETraceArg<Ti1>::info_t::weight>();
    ETArgs1<Ti1> args(EGrabberTrace, TLevel, arg1);
    EGrabberTrace(TLevel, Fid, args.format(), args.address());
}
template <char TLevel, unsigned long long Fid, char Ti1, char Ti2> inline void ETraceContext::hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2) {
    checkTLevel<TLevel>();
    checkFid<Fid>();
    checkTWeight<ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight>();
    ETArgs2<Ti1, Ti2> args(EGrabberTrace, TLevel, arg1, arg2);
    EGrabberTrace(TLevel, Fid, args.format(), args.address());
}
template <char TLevel, unsigned long long Fid, char Ti1, char Ti2, char Ti3> inline void ETraceContext::hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3) {
    checkTLevel<TLevel>();
    checkFid<Fid>();
    checkTWeight<ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight>();
    ETArgs3<Ti1, Ti2, Ti3> args(EGrabberTrace, TLevel, arg1, arg2, arg3);
    EGrabberTrace(TLevel, Fid, args.format(), args.address());
}
template <char TLevel, unsigned long long Fid, char Ti1, char Ti2, char Ti3, char Ti4> inline void ETraceContext::hTrace(const char *format, const typename ETraceArg<Ti1>::info_t::arg_t &arg1, const typename ETraceArg<Ti2>::info_t::arg_t &arg2, const typename ETraceArg<Ti3>::info_t::arg_t &arg3, const typename ETraceArg<Ti4>::info_t::arg_t &arg4) {
    checkTLevel<TLevel>();
    checkFid<Fid>();
    checkTWeight<ETraceArg<Ti1>::info_t::weight + ETraceArg<Ti2>::info_t::weight + ETraceArg<Ti3>::info_t::weight + ETraceArg<Ti4>::info_t::weight>();
    ETArgs4<Ti1, Ti2, Ti3, Ti4> args(EGrabberTrace, TLevel, arg1, arg2, arg3, arg4);
    EGrabberTrace(TLevel, Fid, args.format(), args.address());
}

}

#endif
