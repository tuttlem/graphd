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
     * Creates a new Id object from a stream
     * @return InternalId*
     */
    std::shared_ptr<Id> Id::create(std::istream &is) {
        auto obj = std::make_shared<Id>();
        obj->deserialize(is);

        return obj;
    }

    /**
     * Creates an id object from an existing string value
     * @param
     * @return InternalId*
     */
    std::shared_ptr<Id> Id::fromString(const std::string &s) {
        if (s.length() < 32) {
            throw ValidationException("Id", s, "All ids must be 32-characters in width");
        }

        auto obj = std::make_shared<Id>();

        auto timestampStr = s.substr(0, 8);
        auto pidStr = s.substr(8, 8);
        auto randomStr = s.substr(16, 8);
        auto counterStr = s.substr(24, 8);

        std::stringstream ss;

        ss << std::hex << timestampStr;
        ss >> obj->_value[Id::TIMESTAMP];
        ss.clear();

        ss << std::hex << pidStr;
        ss >> obj->_value[Id::PID];
        ss.clear();

        ss << std::hex << randomStr;
        ss >> obj->_value[Id::RANDOM];
        ss.clear();

        ss << std::hex << counterStr;
        ss >> obj->_value[Id::COUNTER];

        return obj;
    }

    /**
     * Creates an ID object given an existing internal value
     * @param value The internal value of the id
     * @return Id*
     */
    std::shared_ptr<Id> Id::fromValue(const std::array<uint32_t, 4> &value) {
        auto obj = std::make_shared<Id>();
        obj->_value = value;

        return obj;
    }


    /**
     * Serializes this object to the given output stream
     * @param os The output stream to serialize to
     */
    void Id::serialize(std::ostream& os) {
        os.write(reinterpret_cast<const char *>(this->_value.data()), sizeof(this->_value));
    }

    /**
     * Deserializes this object from the given input stream
     * @param is The input stream to deserialize from
     */
    void Id::deserialize(std::istream& is) {
        is.read(reinterpret_cast<char *>(this->_value.data()), sizeof(this->_value));
    }


    /**
     * String representation of this Id
     * @return std::string
     */
    const std::string Id::toString() const {
        std::stringstream ss;

        ss <<  std::right << std::setfill('0') << std::setw(8) << std::hex << this->getTimestamp();
        ss <<  std::right << std::setfill('0') << std::setw(8) << std::hex << this->getPid();
        ss <<  std::right << std::setfill('0') << std::setw(8) << std::hex << this->getRandom();
        ss <<  std::right << std::setfill('0') << std::setw(8) << std::hex << this->getCounter();

        return ss.str();
    }
}