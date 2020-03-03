//
// Created by michael on 27/2/20.
//

#ifndef GRAPHD_ID_HPP
#define GRAPHD_ID_HPP

#include  "../../common.hpp"

namespace graphd {
  /**
  * The basic identifier type for anything internally in the database will
  * be expressed as an InternalId. Structure of this data type is as follows
  * |timestamp|   pid   |  random | counter |
  * |-4 bytes-|-4 bytes-|-4 bytes-|-4 bytes-|
  */
    class Id {
    private:
        static const int TIMESTAMP = 0;
        static const int PID = 1;
        static const int RANDOM = 2;
        static const int COUNTER = 3;

        static unsigned int _currentCounter;
        std::array<int, 4> _value;

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

        const unsigned int getTimestamp() const { return this->_value[Id::TIMESTAMP]; }
        const unsigned int getPid() const { return this->_value[Id::PID]; }
        const unsigned int getRandom() const { return this->_value[Id::RANDOM]; }
        const unsigned int getCounter() const { return this->_value[Id::COUNTER]; }

        Id& operator=(const Id&) = default;
        Id& operator=(Id&&) = default;

        friend bool operator==(const Id& lhs, const Id& rhs) { return lhs._value == rhs._value; }
        friend bool operator!=(const Id& lhs, const Id& rhs) { return lhs._value != rhs._value; }

        /**
         * String representation of this Id
         * @return std::string
         */
        const std::string toString() const;
    };

}


#endif //GRAPHD_ID_HPP
