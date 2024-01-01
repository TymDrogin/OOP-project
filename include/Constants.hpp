#pragma once
#include <string>
#include <unordered_map>

// APP SETTINGS
constexpr int APP_WIDTH = 80;
constexpr int APP_HEIGHT = 24;
constexpr int MAX_LOGS_DISPLAYED = 3;



// HOUSE MANAGER SETTING
constexpr int HOUSE_MANAGER_MIN_ROOMS_DIMENSION = 2;
constexpr int HOUSE_MANAGER_MAX_ROOMS_DIMENSION = 5;


// Used in property
constexpr int DEFAULT_VALUE = -1;

// Default zone properties
constexpr int ZONE_DEFAULT_TEMPERATURE = 25;
constexpr int ZONE_DEFAULT_LIGHT = 0;
constexpr int ZONE_DEFAULT_RADIATION = 0;
constexpr int ZONE_DEFAULT_VIBRATION = 0;
constexpr int ZONE_DEFAULT_HUMIDITY = 0;
constexpr int ZONE_DEFAULT_SMOKE = 0;
constexpr int ZONE_DEFAULT_SOUND = 0;

// Gadgets related controls


// File processing related
const std::string USER_COMMANDS_DIRECTORY_PREFIX = "user-commands/";

// User experience related

extern const std::unordered_map<std::string, std::string> COMMAND_HINTS_LOOKUP;