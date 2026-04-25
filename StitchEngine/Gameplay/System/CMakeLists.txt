add_library(GameplaySystems STATIC
    Private/Gameplay_Systems.cpp
)

target_include_directories(GameplaySystems
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Public
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Private
)

target_link_libraries(GameplaySystems PUBLIC
    GameplayComponents
    SystemRegistry
    ECS
)
