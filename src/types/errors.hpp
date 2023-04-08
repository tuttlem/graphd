//
// Created by michael on 27/2/20.
//

#ifndef GRAPHD_ERRORS_HPP
#define GRAPHD_ERRORS_HPP

#include "../common.hpp"

namespace graphd {

    class GeneralException : public std::exception {
    protected:
        std::string _message;

    public:
        /**
         * Construct with message
         * @param msg
         */
        explicit GeneralException(const std::string& msg) : _message(msg) { }

        virtual ~GeneralException(void) throw() { }

        /** Returns a pointer to the (constant) error description.
         *  @return A pointer to a const char*. The underlying memory
         *  is in possession of the GeneralException object. Callers must
         *  not attempt to free the memory.
         */
        virtual const char* what() const throw() {
            return this->_message.c_str();
        }
    };

    class MetricNotFoundException : public GeneralException {
    protected:
        std::string _metricName;

    public:
        /**
         * Construct with metric name
         * @param metricName The name of the metric
         */
        explicit MetricNotFoundException(const std::string& metricName)
                : _metricName(metricName), GeneralException("The metric " + metricName + " was not found") { }

        virtual ~MetricNotFoundException(void) throw() { }

        /**
         * Retrieves the name of the metric
         * @return std::string
         */
        const std::string getMetricName() { return this->_metricName; }
    };

    class MetricAlreadyExistsException : public GeneralException {
    protected:
        std::string _metricName;

    public:
        /**
         * Construct with metric name
         * @param metricName The name of the metric
         */
        explicit MetricAlreadyExistsException(const std::string& metricName)
                : _metricName(metricName), GeneralException("The metric " + metricName + " already exists") { }

        virtual ~MetricAlreadyExistsException(void) throw() { }

        /**
         * Retrieves the name of the metric
         * @return std::string
         */
        const std::string getMetricName() { return this->_metricName; }
    };

    class ValidationException : public GeneralException {
    protected:
        std::string _typeName;
        std::string _value;
        std::string _reason;

    public:
        /**
         * Construct with type name and failing value
         */
         explicit ValidationException(const std::string &typeName, const std::string &value, const std::string &reason)
            : _typeName(typeName), _value(value), _reason(reason), GeneralException("Invalid " + typeName + " value \"" + value + "\": " + reason) { }

        /**
         * Retrieves the type name being validated
         * @return std::string
         */
        const std::string getTypeName() { return this->_typeName; }

        /**
         * Retrieves the value being validated
         * @return std::string
         */
        const std::string getValue() { return this->_value; }

        /**
         * Retrieves the reason validation failed
         * @return std::string
         */
        const std::string getReason() { return this->_reason; }
    };
}

#endif //GRAPHD_ERRORS_HPP
