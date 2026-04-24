cmake_minimum_required(VERSION 3.16)
project(Core LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Build")

set(ENGINE_VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor" CACHE PATH "Engine vendor dir")

add_subdirectory(Platform)
add_subdirectory(ECS)
add_subdirectory(Engine)
add_subdirectory(Types)
add_subdirectory(ResourceManager)
add_subdirectory(Assertions)

add_library(Core INTERFACE)
target_link_libraries(Core
  INTERFACE Platform
  INTERFACE Engine 
  INTERFACE Types
  INTERFACE ResourceManager
  INTERFACE Assertions
  INTERFACE ECS
)
