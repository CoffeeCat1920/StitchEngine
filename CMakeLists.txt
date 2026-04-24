cmake_minimum_required(VERSION 3.20)
project(StitchEngine LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(vendor INTERFACE)
target_include_directories(vendor INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/json/include
)

add_subdirectory(StitchEngine)
add_subdirectory(Game)
