add_library(Platform STATIC)

target_sources(Platform
  PRIVATE
    Private/SDLWindow.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/Window.hpp
)

target_include_directories(Platform
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)
