add_library(Graphics STATIC)

target_sources(Graphics
  PRIVATE
    Private/GraphicsImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
    Public/Graphics.hpp
)

target_include_directories(Graphics
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(Graphics
  PUBLIC raylib 
  PUBLIC Platform 
)
