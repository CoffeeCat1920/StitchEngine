add_subdirectory(EntityManager)
add_subdirectory(ComponentArray)
add_subdirectory(ComponentManager)
add_subdirectory(SystemManager)

add_library(ECS
    Private/ECS.cpp
)

target_include_directories(ECS PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
    ${CMAKE_CURRENT_SOURCE_DIR}/EntityManager/Public
    ${CMAKE_CURRENT_SOURCE_DIR}/ComponentArray/Public
    ${CMAKE_CURRENT_SOURCE_DIR}/ComponentManager/Public
    ${CMAKE_CURRENT_SOURCE_DIR}/SystemManager/Public
)

target_sources(ECS INTERFACE
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
        Public/ECS.hpp
)

target_link_libraries(ECS
  PUBLIC EntityManager
  PUBLIC ComponentArray
  PUBLIC ComponentManager
  PUBLIC SystemManager
)
