#pragma once
#include <string>

//GRID SETTINGS

// HOUSING GRID SIZE CONTROL
constexpr int APP_HOUSING_ROWS = 2;
constexpr int APP_HOUSING_COLUMNS = 2;

// OFFSET FROM THE ORIGIN
constexpr int APP_HOUSING_OFFSET_X = 4;
constexpr int APP_HOUSING_OFFSET_Y = 4;

// SINGLE TILE DIMENSIONS
constexpr int APP_HOUSING_TILE_HEIGHT = 5;
constexpr int APP_HOUSING_TILE_WIDTH = 5;

// TILE SPACING
constexpr int APP_HOUSING_TILE_SPACING_X = 1;
constexpr int APP_HOUSING_TILE_SPACING_Y = 0;


// GLOBAL APP SETTINGS
// APP SETTINGS
constexpr int APP_WIDTH = 80;
constexpr int APP_HEIGHT = 24;

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

// File processin
constexpr std::string USER_COMMANDS_DIRECTORY_PREFIX = "user-commands/";

