#pragma once
#include <map>
#include <string>
#include <optional>

//NOTE: default value (in case with no min/max) is -1

enum class PropertyType {
    Temperature,
    Light,
    Radiation,
    Vibration,
    Humidity,
    Smoke,
    Sound
};


class PropertyReference {
protected:
    const std::string _name;
    const std::string _units;
    const int _min;
    const int _max;

    PropertyReference(const std::string name, const std::string units, const int min, const int max);

public:


    std::string getName() const;
    std::string getUnits() const;
    int getMax() const;
    int getMin() const;
};

class TemperatureReference : private PropertyReference {
public:
    TemperatureReference();
};

class LightReference : private PropertyReference {
public:
    LightReference();
};

class RadiationReference : private PropertyReference {
public:
    RadiationReference();
};

class VibrationReference : private PropertyReference {
public:
    VibrationReference();
};

class HumidityReference : private PropertyReference {
public:
    HumidityReference();
};

class SmokeReference : private PropertyReference {
public:
    SmokeReference();
};

class SoundReference : private PropertyReference {
public:
    SoundReference();
};
