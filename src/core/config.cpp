//
// Created by michael on 28/2/20.
//

#include "config.hpp"

namespace graphd {

    Config _defaultConfiguration = {
        ._logLevel = "debug"
    };

    /**
     * Factor construction of a config object from a pre-defined
     * configuration file location
     * @param path Location of the configuration file
     * @return std::shared_ptr<Config>
     */
    std::shared_ptr<Config> Config::loadFromFile(const std::string& path) {
        try {
            boost::property_tree::ptree pt;
            boost::property_tree::ini_parser::read_ini(path, pt);

            auto conf = std::make_shared<Config>();

            conf->_logLevel = pt.get<std::string>("logging.level");

            return conf;
        } catch (std::exception& e) {
            log_warn << e.what();
        }

        return nullptr;
    }

    /**
     * Produces a configuration object with the default values
     * @return std::shared_ptr<Config>
     */
    std::shared_ptr<Config> Config::getDefault(void) {
        return std::make_shared<Config>(_defaultConfiguration);
    }

    /**
     * Using the runtime environment, this function will overwrite
     * configurable parameters with environment variables
     * @param conf The configuration object to update
     */
    void Config::adjustWithEnvironment(const std::shared_ptr<Config> conf) {

        if (const char* v = std::getenv("LOG_LEVEL")) {
            conf->_logLevel = v;
        }

    }

}