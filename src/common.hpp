//
// Created by michael on 27/2/20.
//

#ifndef GRAPHD_COMMON_HPP
#define GRAPHD_COMMON_HPP

#include <unistd.h>
#include <stdint.h>

#include <string>
#include <exception>
#include <memory>
#include <ctime>
#include <map>
#include <vector>
#include <array>
#include <iomanip>
#include <iostream>

#define BOOST_LOG_DYN_LINK 1

#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#endif //GRAPHD_COMMON_HPP
