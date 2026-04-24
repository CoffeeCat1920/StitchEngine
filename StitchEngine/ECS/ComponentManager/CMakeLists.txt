add_library(ComponentManager STATIC)
target_sources(ComponentManager
  PRIVATE
    Private/ComponentManager.cpp
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/ComponentManager.hpp
)
target_include_directories(ComponentManager
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)
target_link_libraries(ComponentManager
  PUBLIC Types
  PUBLIC ComponentArray
  PUBLIC EntityManager
)
