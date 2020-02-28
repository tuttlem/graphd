//
// Created by michael on 27/2/20.
//

#ifndef GRAPHD_LOG_HPP
#define GRAPHD_LOG_HPP

#include "../common.hpp"

#define log_trace BOOST_LOG_TRIVIAL(trace)
#define log_debug BOOST_LOG_TRIVIAL(debug)
#define log_info BOOST_LOG_TRIVIAL(info)
#define log_warn BOOST_LOG_TRIVIAL(warning)
#define log_error BOOST_LOG_TRIVIAL(error)
#define log_fatal BOOST_LOG_TRIVIAL(fatal)

#define log_scope BOOST_LOG_NAMED_SCOPE
#define log_fn BOOST_LOG_FUNCTION

namespace graphd {

    /**
     * Setup the logger for the entire application
     * @param level The level of the logger
     * @param path The file path pattern to log to
     */
    void configureLogger(const std::string& level, const std::string& path);

}

#endif //GRAPHD_LOG_HPP
