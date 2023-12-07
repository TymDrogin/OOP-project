#include "property.hpp"
#include "Constants.hpp"


PropertyReference::PropertyReference(const std::string name, const std::string units, const int min, const int max)
        : _name(name), _units(units), _min(min), _max(max) {};

std::string PropertyReference::getName() const {return _name;}
std::string PropertyReference::getUnits() const {return _units;}
int PropertyReference::getMax() const {return _max;}
int PropertyReference::getMin() const {return _min;}

TemperatureReference::TemperatureReference() : PropertyReference("Temperature", "degrees Celsius", -273, DEFAULT_VALUE) {};

LightReference::LightReference() : PropertyReference("Light", "Lumens", 0, DEFAULT_VALUE) {}

RadiationReference::RadiationReference() : PropertyReference("Radiation", "Becquerel", 0, DEFAULT_VALUE) {};

VibrationReference::VibrationReference() : PropertyReference("Vibration (for movement)", "Hertz (in the atmosphere)", 0, DEFAULT_VALUE) {};

HumidityReference::HumidityReference() : PropertyReference("Humidity (Rel.)", "%", 0, 100) {};

SmokeReference::SmokeReference() :  PropertyReference("Smoke", "Obscuration (%)", 0, 100) {};

SoundReference::SoundReference() : PropertyReference("Sound", "Decibels (in the audible range)", 0, DEFAULT_VALUE) {};