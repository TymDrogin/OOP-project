cmake_minimum_required(VERSION 3.26)
project(OOP-project)

set(CMAKE_CXX_STANDARD 20)

# Find the ncurses package
find_package(Curses REQUIRED)

# Include directories
include_directories(include ${CURSES_INCLUDE_DIR})

# Add source files from the 'src' directory
file(GLOB SOURCES "src/*.cpp")

# Add source files from the 'lib' directory
file(GLOB LIB_SOURCES "lib/*.cpp")

# Add all source files to the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${LIB_SOURCES}
        src/app.cpp)

# Link the executable with the ncurses library
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

