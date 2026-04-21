add_library(TextureHandler STATIC)

target_sources(TextureHandler
  PRIVATE
    Private/TextureHandlerImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/TextureHandler.hpp
)

target_include_directories(TextureHandler
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(TextureHandler
  PUBLIC raylib 
  PUBLIC Types
)
