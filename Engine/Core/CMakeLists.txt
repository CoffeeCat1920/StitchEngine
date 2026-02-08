add_library(Core STATIC)

target_sources(Core
  PRIVATE
    Private/CoreImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
    Public/Core.hpp
)

target_include_directories(Core
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(Core
  PUBLIC raylib 
  PUBLIC Platform 
)
