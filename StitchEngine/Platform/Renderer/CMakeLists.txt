add_library(Renderer STATIC)

target_sources(Renderer
  PRIVATE
    Private/RendererImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/Renderer.hpp
)

target_include_directories(Renderer
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(Renderer
  PUBLIC raylib 
  PUBLIC Types
)
