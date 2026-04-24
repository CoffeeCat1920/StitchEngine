add_library(ComponentRegistry
    Private/ComponentRegistry.cpp
)

target_sources(ComponentRegistry
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/ComponentRegistry.hpp
)

target_include_directories(ComponentRegistry
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
    ${ENGINE_VENDOR_DIR}
)

target_link_libraries(ComponentRegistry
  PUBLIC Types
  PUBLIC ComponentArray
  PUBLIC EntityManager
)
