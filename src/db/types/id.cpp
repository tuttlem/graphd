//
// Created by michael on 27/2/20.
//

#include "id.hpp"

namespace graphd {
    /* kick the counter part of the ID off as a random number */
    unsigned int Id::_currentCounter = std::rand();

    /**
     * Creates a new, randomized identifier usable within the database system
     * @return InternalId*
     */
    std::shared_ptr<Id> Id::create() {
        auto obj = std::make_shared<Id>();

        // timestamp
        std::time_t timestamp = std::time(nullptr);
        std::localtime(&timestamp);

        // random
        auto random = std::rand();

        // counter
        auto counter = Id::_currentCounter++;

        // pid
        auto pid = getpid();

        // assemble the value now
        obj->_value[Id::TIMESTAMP] = timestamp;
        obj->_value[Id::PID] = pid;
        obj->_value[Id::RANDOM] = random;
        obj->_value[Id::COUNTER] = counter;

        return obj;
    }

    /**
     * String representation of this Id
     * @return std::string
     */
    const std::string Id::toString() {
        std::stringstream ss;

        ss <<  std::right << std::setfill('0') << std::setw(8) << std::hex << this->getTimestamp();
        ss <<  std::right << std::setfill('0') << std::setw(8) << std::hex << this->getPid();
        ss <<  std::right << std::setfill('0') << std::setw(8) << std::hex << this->getRandom();
        ss <<  std::right << std::setfill('0') << std::setw(8) << std::hex << this->getCounter();

        return ss.str();
    }
}