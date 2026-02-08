cmake_minimum_required(VERSION 3.16)
project(Engine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Build")

add_subdirectory(Platform)
add_subdirectory(Core)
add_subdirectory(Types)

add_library(Engine INTERFACE)

target_link_libraries(Engine
  INTERFACE Platform
  INTERFACE Core 
)
