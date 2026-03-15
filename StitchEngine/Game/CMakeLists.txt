add_library(Game STATIC)

target_sources(Game
  PRIVATE
    Private/GameImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
    Public/Game.hpp
)

target_include_directories(Game
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(Game 
  PUBLIC raylib 
  PUBLIC Platform 
)
