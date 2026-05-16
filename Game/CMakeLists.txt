cmake_minimum_required(VERSION 3.20)
project(Game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Game)

target_link_libraries(Game
  PRIVATE Engine
  PRIVATE Gameplay
)

target_sources(Game
  PRIVATE 
    ./src/main.cpp
    ./Components/components.hpp
    ./Systems/systems.hpp
)
