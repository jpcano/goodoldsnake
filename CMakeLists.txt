cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include(cmake/CPM.cmake)

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(SnakeGame
  src/main.cpp
  src/game.cpp
  src/controller.cpp
  src/renderer.cpp
  src/snake.cpp
  src/food.cpp
  src/score.cpp
)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(SnakeGame ${SDL2_LIBRARIES})

# the install option has to be explicitly set to allow installation
CPMAddPackage(
  NAME cxxopts
  GITHUB_REPOSITORY jarro2783/cxxopts
  VERSION 3.2.0
  OPTIONS
    "CXXOPTS_BUILD_EXAMPLES NO"
    "CXXOPTS_BUILD_TESTS NO"
    "CXXOPTS_ENABLE_INSTALL YES"
)

CPMAddPackage(
  NAME nlohmann_json
  VERSION 3.11.3
  GITHUB_REPOSITORY nlohmann/json
  OPTIONS
  "JSON_BuildTests OFF"
)

target_link_libraries(SnakeGame cxxopts::cxxopts)
target_link_libraries(SnakeGame nlohmann_json::nlohmann_json)
