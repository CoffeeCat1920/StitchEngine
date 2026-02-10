add_library(GraphicsManager STATIC)

target_sources(GraphicsManager
  PRIVATE
    Private/GraphicsManagerImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
    Public/GraphicsManager.hpp
)

target_include_directories(GraphicsManager
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(GraphicsManager
  PUBLIC raylib 
  PUBLIC Platform 
)
