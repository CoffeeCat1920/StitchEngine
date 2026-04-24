add_library(ComponentRegistry INTERFACE)
target_sources(ComponentRegistry
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/ComponentRegistry.hpp
)
target_include_directories(ComponentRegistry
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)
target_link_libraries(ComponentRegistry
  INTERFACE Types
  INTERFACE ComponentArray
  INTERFACE EntityManager
  INTERFACE vendor
)
