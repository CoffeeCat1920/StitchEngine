add_library(Window STATIC)

target_sources(Window
  PRIVATE
    Private/WindowImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/Window.hpp
)

target_include_directories(Window
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(Window
  PUBLIC raylib 
  PUBLIC Types
)
