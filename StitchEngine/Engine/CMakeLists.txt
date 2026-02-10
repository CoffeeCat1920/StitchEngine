add_library(Engine STATIC)

target_sources(Engine
  PRIVATE
    Private/EngineImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
    Public/Engine.hpp
)

target_include_directories(Engine
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(Engine
  PUBLIC raylib 
  PUBLIC Platform 
)
