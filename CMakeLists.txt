cmake_minimum_required(VERSION 3.20)
project(StitchEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(MyProgram)

target_sources(MyProgram
  PRIVATE 
    ./src/main.cpp
)
