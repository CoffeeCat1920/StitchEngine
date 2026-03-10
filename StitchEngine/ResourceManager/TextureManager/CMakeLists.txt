add_library(TextureManager STATIC)

target_sources(TextureManager
  PRIVATE
    Private/TextureManagerImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
    Public/TextureManager.hpp
)

target_include_directories(TextureManager
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(TextureManager
  PUBLIC raylib 
  PUBLIC Platform 
)
