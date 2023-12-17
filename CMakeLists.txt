cmake_minimum_required(VERSION 3.26)
project(OOP-project)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(include)

# Add source files from the 'src' directory
file(GLOB SOURCES "src/*.cpp")

# Add source files from the 'lib' directory
file(GLOB LIB_SOURCES "lib/*.cpp")

# Add all source files to the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${LIB_SOURCES}
        src/utils.cpp)

# Link the executable with the pdcurses library
target_link_libraries(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/pdcurses.a")