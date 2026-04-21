add_library(RenderHandler STATIC)

target_sources(RenderHandler
  PRIVATE
    Private/RenderHandlerImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/RenderHandler.hpp
)

target_include_directories(RenderHandler
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(RenderHandler
  PUBLIC raylib 
  PUBLIC Types
)
