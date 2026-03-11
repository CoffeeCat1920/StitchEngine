add_library(Types INTERFACE)

target_link_libraries(Types
  INTERFACE Assertions
)

target_include_directories(Types
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)
