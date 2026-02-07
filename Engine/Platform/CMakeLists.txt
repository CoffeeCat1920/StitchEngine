add_library(Platform STATIC)

target_sources(Platform
  PRIVATE
    Private/WindowImpl.cpp
    Private/RendererImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/Window.hpp
      Public/Renderer.hpp
)

target_include_directories(Platform
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(Platform
  PUBLIC raylib 
)
