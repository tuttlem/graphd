//
// Created by michael on 27/2/20.
//

#ifndef GRAPHD_TELEMETRY_HPP
#define GRAPHD_TELEMETRY_HPP

#include "../common.hpp"
#include "../types/errors.hpp"
#include "../types/interfaces.hpp"

namespace graphd {

    template<typename T>
    struct Quantum {
        std::time_t when;       /* when this quantum was recorded */
        T sample;               /* the sample being recorded */
    };

    class Telemetry : public TelemetryLike {
    private:
        std::map<std::string, std::vector<Quantum<double>>> _samples;

    public:
        /**
         * Default constructor
         */
        Telemetry(void) {

        }

        Telemetry(const Telemetry& t) = delete;
        Telemetry(const Telemetry&& t) = delete;

        /**
         * Destructor
         */
        virtual ~Telemetry() { }

        /**
         * Validates that a requested metric exists
         * @param name The name of the metric
         */
        void validateMetric(const std::string& name);

        /**
         * Creates a metric
         * @param name The name of the metric to create
         */
        void addMetric(const std::string& name);

        /**
         * Increments the value of a counter
         * @param name The name of the counter to increment
         */
        void increment(const std::string& name);

        /**
         * Increments the value of a counter
         * @param name The name of the counter to increment
         */
        void reset(const std::string& name);

        /**
         * Creates a metric
         * @param name The name of the metric to create
         */
        void sample(const std::string& name, const double value);

        /**
         * Gets the last value of a given metric
         * @param name The name of the metric
         * @return double
         */
        double last(const std::string& name);
    };

}

#endif //GRAPHD_TELEMETRY_HPP
