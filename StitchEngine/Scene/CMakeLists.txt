add_library(Scene
    Private/Scene.cpp
)

target_sources(Scene
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/Scene.hpp
)

target_include_directories(Scene
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
    ${ENGINE_VENDOR_DIR}
)

target_link_libraries(Scene
  PUBLIC Types
  PUBLIC ECS
  PUBLIC Registry
)
