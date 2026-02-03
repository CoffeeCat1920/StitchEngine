cmake_minimum_required(VERSION 3.20)
project(StitchEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Game)

target_link_libraries(Game
  PRIVATE Engine
)

target_sources(Game
  PRIVATE 
    ./src/main.cpp
)
