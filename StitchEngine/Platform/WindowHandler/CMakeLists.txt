add_library(WindowHandler STATIC)

target_sources(WindowHandler
  PRIVATE
    Private/WindowHandlerImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/WindowHandler.hpp
)

target_include_directories(WindowHandler
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(WindowHandler
  PUBLIC raylib 
  PUBLIC Types
)
