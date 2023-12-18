#include "zone.hpp"
#include "Constants.hpp"
Zone::Zone(int ID) : _ruleProcessor(_rules) , _ID(ID) {
    initializeProperties();
}

void Zone::initializeProperties() {
    static int callCounter = 0;
    if (0 == callCounter) {
        _properties[PropertyType::Temperature] = ZONE_DEFAULT_TEMPERATURE;
        _properties[PropertyType::Light] = ZONE_DEFAULT_LIGHT;
        _properties[PropertyType::Radiation] = ZONE_DEFAULT_RADIATION;
        _properties[PropertyType::Vibration] = ZONE_DEFAULT_VIBRATION;
        _properties[PropertyType::Humidity] = ZONE_DEFAULT_HUMIDITY;
        _properties[PropertyType::Smoke] = ZONE_DEFAULT_SMOKE;
        _properties[PropertyType::Sound] = ZONE_DEFAULT_SOUND;
        callCounter++;
    }
}

void Zone::nextStep() {

}
