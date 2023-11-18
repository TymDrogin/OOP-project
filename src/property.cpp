#include "property.hpp"
PropertyReference::PropertyReference(std::string name, std::string units, std::optional<int> min, std::optional<int> max)
    : _name(name), _units(units), _min(min), _max(max) {};

std::string PropertyReference::getName() const {return _name;}
std::string PropertyReference::getUnits() const {return _units;}
std::optional<int> PropertyReference::getMin() const {return _min;}
std::optional<int> PropertyReference::getMax() const {return _max;}

std::map<std::string, PropertyReference> PropertyReferenceTable = {
        {"Temperature",PropertyReference(
                "Temperature",
                "degrees Celsius",
                -273,
                0)
        },
        {"Light",PropertyReference(
                "Light",
                "Lumens",
                0,
                std::nullopt)
        },
        {"Radiation",PropertyReference(
                "Radiation",
                "Becquerel",
                0,
                std::nullopt)
        },
        {"Vibration (for movement)",PropertyReference(
                "Vibration (for movement)",
                "Hertz (in the atmosphere)",
                0,
                std::nullopt)
        },
        {"Humidity",PropertyReference(
                "Humidity",
                "%",
                0,
                100)
        },
        {"Smoke",PropertyReference(
                "Smoke",
                "Obscuration(%)",
                0,
                100)
        },
        {"Sound",PropertyReference(
                "Sound",
                "Decibels (in the audible range)",
                0,
                std::nullopt)
        }
};

