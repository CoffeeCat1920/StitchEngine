add_subdirectory(ComponentRegistry)
add_subdirectory(SystemRegistry)

add_library(Registry INTERFACE)

target_link_libraries(Registry
  INTERFACE ComponentRegistry
  INTERFACE Registry 
)
