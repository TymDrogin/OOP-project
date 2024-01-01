#include "zone.hpp"
#include "Constants.hpp"
Zone::Zone(int ID) : _ruleProcessor(_rules) , _ID(ID) {
    initializeProperties();
}

void Zone::initializeProperties() {
        _properties[PropertyType::Temperature] = ZONE_DEFAULT_TEMPERATURE;
        _properties[PropertyType::Light] = ZONE_DEFAULT_LIGHT;
        _properties[PropertyType::Radiation] = ZONE_DEFAULT_RADIATION;
        _properties[PropertyType::Vibration] = ZONE_DEFAULT_VIBRATION;
        _properties[PropertyType::Humidity] = ZONE_DEFAULT_HUMIDITY;
        _properties[PropertyType::Smoke] = ZONE_DEFAULT_SMOKE;
        _properties[PropertyType::Sound] = ZONE_DEFAULT_SOUND;
}


int Zone::getID() const {return _ID;};
int Zone::getNumSensors() const {
    return _sensors.size();
}

int Zone::getNumDevices() const {
    return _devises.size();
}

int Zone::getNumRules() const {
    return _rules.size();
}

std::map<PropertyType, int> Zone::getZoneProps() const {
    return _properties;
}

void Zone::nextSimulationStep() {
    for(auto &device : _devises) {
        device->work();
    }
    for(auto &rule : _rules) {
        rule->evaluate();
    }
}



