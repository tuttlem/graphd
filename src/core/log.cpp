//
// Created by michael on 27/2/20.
//

#include  "./log.hpp"

namespace graphd {
    namespace logging = boost::log;
    namespace src = boost::log::sources;
    namespace sinks = boost::log::sinks;
    namespace keywords = boost::log::keywords;
    namespace expressions = boost::log::expressions;

    /**
     * Setup the logger for the entire application
     * @param level The level of the logger
     * @param path The file path pattern to log to
     */
    void configureLogger(const std::string& level, const std::string& path = "graphd_%N.log") {
        logging::add_common_attributes();
        logging::core::get()->add_global_attribute(
            "Scope",
            logging::attributes::named_scope()
        );

        // only setup the file logger if a path was specified
        if (path.length() > 0) {
            auto fmtTimeStamp = expressions::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f");
            auto fmtThreadId = expressions::attr<boost::log::attributes::current_thread_id::value_type>("ThreadID");
            auto fmtSeverity = expressions::attr<boost::log::trivial::severity_level>("Severity");
            auto fmtScope = expressions::format_named_scope("Scope",
                keywords::format = "%n(%f:%l)",
                keywords::iteration = expressions::reverse,
                keywords::depth = 2);

            boost::log::formatter logFmt =
                    boost::log::expressions::format("[%1%] (%2%) [%3%] [%4%] %5%")
                    % fmtTimeStamp % fmtThreadId % fmtSeverity % fmtScope
                    % boost::log::expressions::smessage;

            logging::add_file_log(
                    keywords::file_name = path,
                    keywords::rotation_size = 10 * 1024 * 1024,
                    keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
                    keywords::format = logFmt
            );
        }

        logging::trivial::severity_level filterLevel = logging::trivial::info;

        if (level == "trace") {
            filterLevel = logging::trivial::trace;
        } else if (level == "debug") {
            filterLevel = logging::trivial::debug;
        } else if (level ==  "info") {
            filterLevel = logging::trivial::info;
        } else if (level == "warning") {
            filterLevel = logging::trivial::warning;
        } else if (level == "error") {
            filterLevel = logging::trivial::error;
        } else if (level ==  "fatal") {
            filterLevel = logging::trivial::fatal;
        }

        logging::core::get()->set_filter(
                logging::trivial::severity >= filterLevel
        );

    }

}