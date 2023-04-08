//
// Created by michael on 27/2/20.
//

#ifndef GRAPHD_ID_HPP
#define GRAPHD_ID_HPP

#include  "../../common.hpp"
#include  "../../types/errors.hpp"
#include "../io/serialization.hpp"

namespace graphd {
  /**
  * The basic identifier type for anything internally in the database will
  * be expressed as an InternalId. Structure of this data type is as follows
  * |timestamp|   pid   |  random | counter |
  * |-4 bytes-|-4 bytes-|-4 bytes-|-4 bytes-|
  */
    class Id : Serializable {
    private:
        static const int TIMESTAMP = 0;
        static const int PID = 1;
        static const int RANDOM = 2;
        static const int COUNTER = 3;

        static unsigned int _currentCounter;
        uint32_t _value[4];

    public:
        /** Default constructor */
        Id(void) = default;
        /** Copy constructor */
        Id(const Id&) = default;
        /** Move constructor */
        Id(Id&&) = default;

        /**
         * Creates a new, randomized identifier usable within the database system
         * @return Id*
         */
        static std::shared_ptr<Id> create();

        /**
         * Creates a new Id object from a stream
         * @return InternalId*
         */
        static std::shared_ptr<Id> create(std::istream &is);

        /**
         * Creates an ID object given an existing string representation
         * @param s The string representation of the id
         * @return Id*
         */
        static std::shared_ptr<Id> fromString(const std::string &s);

        const unsigned int getTimestamp() const { return this->_value[Id::TIMESTAMP]; }
        const unsigned int getPid() const { return this->_value[Id::PID]; }
        const unsigned int getRandom() const { return this->_value[Id::RANDOM]; }
        const unsigned int getCounter() const { return this->_value[Id::COUNTER]; }

        Id& operator=(const Id&) = default;
        Id& operator=(Id&&) = default;

        friend bool operator==(const Id& lhs, const Id& rhs) { return lhs._value == rhs._value; }
        friend bool operator!=(const Id& lhs, const Id& rhs) { return lhs._value != rhs._value; }

        friend bool operator<(const Id& lhs, const Id& rhs) { return lhs._value < rhs._value; }
        friend bool operator>(const Id& lhs, const Id& rhs) { return lhs._value > rhs._value; }
        friend bool operator<=(const Id& lhs, const Id& rhs) { return lhs._value <= rhs._value; }
        friend bool operator>=(const Id& lhs, const Id& rhs) { return lhs._value >= rhs._value; }

        /**
         * Serializes this object to the given output stream
         * @param os The output stream to serialize to
         */
        void serialize(std::ostream& os);

        /**
         * Deserializes this object from the given input stream
         * @param is The input stream to deserialize from
         */
        void deserialize(std::istream& is);

        /**
         * String representation of this Id
         * @return std::string
         */
        const std::string toString() const;
    };

}


#endif //GRAPHD_ID_HPP
