add_subdirectory(ComponentRegistry)

add_library(Registry INTERFACE)

target_link_libraries(Registry
  INTERFACE ComponentRegistry
)
