add_library(Assertions INTERFACE)

target_include_directories(Assertions
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)
