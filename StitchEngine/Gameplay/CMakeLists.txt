add_subdirectory(Component)
add_subdirectory(System)

add_library(Gameplay INTERFACE)

target_link_libraries(Gameplay INTERFACE
    GameplayComponents
    GameplaySystems
    Types
)
