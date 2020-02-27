//
// Created by michael on 27/2/20.
//

#include "telemetry.hpp"

namespace graphd {

    /**
     * Validates that a requested metric exists
     * @param name The name of the metric
     */
    void Telemetry::validateMetric(const std::string& name) {
        // make sure the metric exists
        if (this->_samples.find(name) == this->_samples.end()) {
            throw MetricNotFoundException(name);
        }
    }

    /**
     * Creates a metric
     * @param name The name of the metric to create
     */
    void Telemetry::addMetric(const std::string& name) {
        // make sure that the metric doesn't yet exist
        if (this->_samples.find(name) != this->_samples.end()) {
            throw MetricAlreadyExistsException(name);
        }

        // create the entry for the metric
        this->_samples.insert(std::pair<std::string, std::vector<Quantum<double>>>(name, std::vector<Quantum<double>>()));

        // seed the metric off with zero
        this->sample(name, 0.0);
    }

    /**
     * Increments the value of a counter
     * @param name The name of the counter to increment
     */
    void Telemetry::increment(const std::string& name) {
        this->sample(name, 1.0);
    }

    /**
     * Increments the value of a counter
     * @param name The name of the counter to increment
     */
    void Telemetry::reset(const std::string& name) {
        this->validateMetric(name);

        // clear and seed the metric
        this->_samples[name].clear();
        this->sample(name, 0.0);
    }

    /**
     * Creates a metric
     * @param name The name of the metric to create
     */
    void Telemetry::sample(const std::string& name, const double value) {
        this->validateMetric(name);

        // create the new sample, and store
        Quantum<double> q = Quantum<double>();
        q.when = std::time(nullptr);
        q.sample = value;

        this->_samples[name].push_back(q);
    }

    /**
     * Gets the last value of a given metric
     * @param name The name of the metric
     * @return double
     */
    double Telemetry::last(const std::string& name) {
        this->validateMetric(name);

        auto v = this->_samples[name];
        return v[v.size() - 1].sample;
    }

}