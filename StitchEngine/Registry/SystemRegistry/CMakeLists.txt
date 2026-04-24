add_library(SystemRegistry
    Private/SystemRegistry.cpp
)

target_sources(SystemRegistry
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/SystemRegistry.hpp
)

target_include_directories(SystemRegistry
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
    ${ENGINE_VENDOR_DIR}
)

target_link_libraries(SystemRegistry
  PUBLIC Types
  PUBLIC ECS
)
