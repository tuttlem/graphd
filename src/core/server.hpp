//
// Created by michael on 27/2/20.
//

#ifndef GRAPHD_SERVER_HPP
#define GRAPHD_SERVER_HPP

#include "../common.hpp"
#include "../types/interfaces.hpp"
#include "telemetry.hpp"
#include "config.hpp"

namespace graphd {

    /**
     * The Server class is responsible for standing up and initializing resources.
     * It will also act as the common hub to manage all application resource, as
     * well as binding to the network
     */
    class Server : public ServerLike {
    private:
        std::shared_ptr<TelemetryLike> _telemetry;
        std::shared_ptr<Config> _config;

    public:
        /**
         * Default constructor
         */
        Server(
            std::shared_ptr<Config> config,
            std::shared_ptr<TelemetryLike> telemetry
        ) : _telemetry(telemetry), _config(config) { }

        Server(const Server&) = delete;
        Server(Server&&) = delete;

        virtual ~Server(void) = default;

        /**
         * Retrieves the telemetry system for this server
         * @return std::shared_ptr<TelemetryLike>
         */
        std::shared_ptr<TelemetryLike> getTelemetry(void) { return this->_telemetry; }

        /**
         * Retrieves the configuration information for this server
         * @return std::shared_ptr<Config>
         */
        std::shared_ptr<Config> getConfig(void) { return this->_config; }

    private:
    };

}

#endif //GRAPHD_SERVER_HPP
