add_subdirectory(TextureManager)

add_library(ResourceManager STATIC)

target_sources(ResourceManager
  PRIVATE
  Private/ResourceManagerImpl.cpp
  PUBLIC
  FILE_SET HEADERS
  BASE_DIRS Public
  FILES
  Public/ResourceManager.hpp
)

target_include_directories(ResourceManager
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

target_link_libraries(ResourceManager 
  INTERFACE TextureManager 
  PUBLIC Platform 
)
