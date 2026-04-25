add_library(GameplayComponents INTERFACE)

target_include_directories(GameplayComponents INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

target_link_libraries(GameplayComponents INTERFACE
    ECS
    ComponentRegistry
)
