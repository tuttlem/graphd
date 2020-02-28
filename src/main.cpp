
#include <iostream>
#include "./common.hpp"
#include "./core/log.hpp"
#include "./core/config.hpp"

int main() {
    try {
        // auto config = graphd::Config::getDefault();

        auto config = graphd::Config::loadFromFile("graphd.conf");
        graphd::Config::adjustWithEnvironment(config);

        log_info << config->_logLevel;
    } catch (std::exception e) {
        BOOST_LOG_TRIVIAL(error) << "Bad shit";
    }

    return 0;
}