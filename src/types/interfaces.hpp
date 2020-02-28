//
// Created by michael on 27/2/20.
//

#ifndef GRAPHD_INTERFACES_HPP
#define GRAPHD_INTERFACES_HPP

#include "../common.hpp"
#include "../core/config.hpp"

namespace graphd {

    class TelemetryLike {
    public:
        virtual void validateMetric(const std::string& name) = 0;
        virtual void addMetric(const std::string& name) = 0;
        virtual void increment(const std::string& name) = 0;
        virtual void reset(const std::string& name) = 0;
        virtual void sample(const std::string& name, const double value) = 0;
        virtual double last(const std::string& name) = 0;
    };

    class ServerLike {
    public:
        virtual std::shared_ptr<TelemetryLike> getTelemetry(void) = 0;
        virtual std::shared_ptr<Config> getConfig(void) = 0;
    };

}

#endif //GRAPHD_INTERFACES_HPP
