//
// Created by michael on 27/2/20.
//

#include  "./properties.hpp"

namespace graphd {
    typedef std::variant<bool, int, float, std::string> property_value_t;
    typedef std::map<std::string, property_value_t> property_map_t;
    typedef std::map<id_val_t, property_map_t> data_map_t;

    std::string propertyValueToString(const property_value_t& value) {
        switch (value.index()) {
            case 0:
                return std::to_string(std::get<0>(value));
            case 1:
                return std::to_string(std::get<1>(value));
            case 2:
                return std::to_string(std::get<2>(value));
            case 3:
                return "\"" + std::get<3>(value) + "\"";
            default:
                return "";
        }
    }

    std::string propertyMapToString(const property_map_t& map) {
        std::string result = "{";
        for (auto& [key, value] : map) {
            result += "\"" + key + + "\": " + propertyValueToString(value) + ", ";
        }
        result += "}";
        return result;
    }
}

