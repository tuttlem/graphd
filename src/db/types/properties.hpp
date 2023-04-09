//
// Created by michael on 27/2/20.
//

#ifndef GRAPHD_PROPERTIES_HPP
#define GRAPHD_PROPERTIES_HPP

#include  "../../common.hpp"
#include  "./id.hpp"

namespace graphd {
    typedef std::variant<bool, int, float, std::string> property_value_t;
    typedef std::map<std::string, property_value_t> property_map_t;
    typedef std::map<id_val_t, property_map_t> data_map_t;

    std::string propertyValueToString(const property_value_t& value);

    std::string propertyMapToString(const property_map_t& map) ;
}

#endif //GRAPHD_PROPERTIES_HPP
