#include "property.hpp"
#include <memory>

class Device {
protected:
    const char symbol;
    bool _state;

    PropertyType _affectedPropertyType; // Which property in the room does Gadget affects
    int _propertyAffectValue;           // On how much does it change it in the one program step

    std::shared_ptr<std::map<PropertyType, int>> _propertyMap; // Pointer to the map of room properties

public:
    virtual void work() = 0;
};

class Fridge : Device {
public:
    Fridge();
    void work() override;
};



