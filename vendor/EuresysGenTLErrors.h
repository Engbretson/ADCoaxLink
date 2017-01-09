/* Copyright Euresys 2014 */

#ifndef EURESYS_GENTL_ERRORS_HEADER_FILE
#define EURESYS_GENTL_ERRORS_HEADER_FILE

#include <stdexcept>

/** @file
    Defines exception used by Euresys::GenTL and Euresys::EGrabber
 **/

namespace EURESYS_NAMESPACE {

namespace gc = GenICam::Client;
namespace ge = GenICam::Client::Euresys;

template<typename T>
std::string intToString(T n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}

/** cti loading error */
class cti_loading_error: public std::runtime_error {
    public:
        explicit cti_loading_error(const std::string &path)
        : std::runtime_error(std::string("Cannot load ") + path)
        {}
};

/** a cti symbol is missing */
class missing_gentl_symbol: public std::runtime_error {
    public:
        explicit missing_gentl_symbol(const std::string &path, const std::string &symbol)
        : std::runtime_error(std::string("Missing symbol ") + symbol + " in " + path)
        {}
};

/** an info command did not return the expected data type */
class unexpected_data_type: public std::runtime_error {
    public:
        gc::INFO_DATATYPE type;
        explicit unexpected_data_type(gc::INFO_DATATYPE type)
        : std::runtime_error(std::string("Unexpected data type ") +
                             intToString(type))
        , type(type)
        {}
};

/** a command did not return the expected data size */
class unexpected_data_size: public std::runtime_error {
    public:
        size_t expected;
        size_t returned;
        explicit unexpected_data_size(size_t expected, size_t returned)
        : std::runtime_error(std::string("Unexpected data size, expected ") +
                             intToString(expected) + " but got " +
                             intToString(returned))
        , expected(expected)
        , returned(returned)
        {}
};

/** something wrong with the parameters provided by the caller */
class client_error: public std::runtime_error {
    public:
        explicit client_error(const std::string &msg)
        : std::runtime_error(msg)
        {}
};

/** some error reported by the GenTL library */
class gentl_error: public std::runtime_error {
    public:
        gc::GC_ERROR gc_err;
        explicit gentl_error(gc::GC_ERROR err)
        : std::runtime_error(std::string("GenTL error ") +
                             intToString(err))
        , gc_err(err)
        {}
        gentl_error(gc::GC_ERROR err, const std::string &description)
        : std::runtime_error(std::string("GenTL error ") +
                             intToString(err) +
                             ", " + description)
        , gc_err(err)
        {}
};

/** thread error */
class thread_error: public std::runtime_error {
    public:
        thread_error(const std::string &msg)
        : std::runtime_error(msg)
        {}
};

} // namespace EURESYS_NAMESPACE

#endif
