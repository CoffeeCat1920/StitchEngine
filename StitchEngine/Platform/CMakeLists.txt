add_subdirectory(Window)
add_subdirectory(Renderer)

add_library(Platform INTERFACE)

target_link_libraries(Platform
  INTERFACE Window 
  INTERFACE Renderer 
  INTERFACE Types 
)
