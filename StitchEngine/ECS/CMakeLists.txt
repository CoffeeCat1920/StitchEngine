add_subdirectory(EntityManager)
add_subdirectory(ComponentArray)
add_subdirectory(ComponentManager)
add_subdirectory(Utils)
add_subdirectory(SystemManager)
add_subdirectory(ComponentRegistry)

add_library(ECS INTERFACE)

target_include_directories(ECS INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
    ${CMAKE_CURRENT_SOURCE_DIR}/EntityManager/Public
    ${CMAKE_CURRENT_SOURCE_DIR}/ComponentArray/Public
    ${CMAKE_CURRENT_SOURCE_DIR}/ComponentManager/Public
    ${CMAKE_CURRENT_SOURCE_DIR}/SystemManager/Public
    ${CMAKE_CURRENT_SOURCE_DIR}/ComponentRegistry/Public
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils/Public
)

target_sources(ECS INTERFACE
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
        Public/ECS.hpp
)

target_link_libraries(ECS
  INTERFACE EntityManager
  INTERFACE ComponentArray
  INTERFACE ComponentManager
  INTERFACE SystemManager
  INTERFACE ComponentRegistry
  INTERFACE Utils
  INTERFACE vendor
)
