#pragma once
#include <map>
#include <string>
#include <optional>

typedef std::pair<std::string, int> Property;

// Used to define a reference of the property with name, units, min and max value
class PropertyReference {
private:
    const std::string _name;
    const std::string _units;
    const std::optional<int> _min;
    const std::optional<int> _max;

public:
    PropertyReference(std::string name, std::string units, std::optional<int> min, std::optional<int> max);

    std::string getName() const;
    std::string getUnits() const;
    std::optional<int> getMin() const;
    std::optional<int> getMax() const;
};

extern std::map<std::string, PropertyReference> PropertyReferenceTable;
