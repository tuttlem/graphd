//
// Created by michael on 27/2/20.
//

#ifndef GRAPHD_SERVER_HPP
#define GRAPHD_SERVER_HPP

#include "../common.hpp"
#include "../types/interfaces.hpp"
#include "telemetry.hpp"

namespace graphd {

    /**
     * The Server class is responsible for standing up and initializing resources.
     * It will also act as the common hub to manage all application resource, as
     * well as binding to the network
     */
    class Server : public ServerLike {
    private:
        std::shared_ptr<TelemetryLike> _telemetry;

    public:
        /**
         * Default constructor
         */
        Server(std::shared_ptr<TelemetryLike> telemetry) : _telemetry(telemetry) { }

        Server(const Server&) = delete;
        Server(Server&&) = delete;

        virtual ~Server(void) = default;

        /**
         * Retrieves the telemetry system for this server
         * @return TelemetryLike&
         */
        std::shared_ptr<TelemetryLike> getTelemetry(void) { return this->_telemetry; }

    private:
    };

}

#endif //GRAPHD_SERVER_HPP
