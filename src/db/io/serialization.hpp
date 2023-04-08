//
// Created by michael on 8/04/23.
//

#ifndef GRAPHD_SERIALIZATION_HPP
#define GRAPHD_SERIALIZATION_HPP

#include  "../../common.hpp"

namespace graphd {
    class Serializable {
    public:
        virtual void serialize(std::ostream& os) = 0;
        virtual void deserialize(std::istream& is) = 0;
    };
}

#endif //GRAPHD_INTERFACES_HPP