add_library(Platform STATIC)

target_sources(Platform
  PRIVATE
    Private/RaylibWindow.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
    Public/WindowImpl.hpp
)

target_include_directories(Platform
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(Platform
  PUBLIC raylib 
)
