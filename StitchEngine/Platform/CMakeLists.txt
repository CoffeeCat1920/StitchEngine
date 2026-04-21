add_subdirectory(WindowHandler)
add_subdirectory(RenderHandler)
add_subdirectory(TextureHandler)

add_library(Platform INTERFACE)

target_link_libraries(Platform
  INTERFACE WindowHandler 
  INTERFACE RenderHandler 
  INTERFACE TextureHandler
  INTERFACE Types 
)
