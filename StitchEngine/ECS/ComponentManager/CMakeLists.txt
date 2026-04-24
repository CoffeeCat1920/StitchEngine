add_library(ComponentManager INTERFACE)
target_sources(ComponentManager
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/ComponentManager.hpp
)
target_include_directories(ComponentManager
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)
target_link_libraries(ComponentManager
  INTERFACE Types
  INTERFACE ComponentArray
  INTERFACE EntityManager
)
