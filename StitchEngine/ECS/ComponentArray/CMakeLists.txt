add_library(ComponentArray INTERFACE)
target_sources(ComponentArray
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/ComponentArray.hpp
)
target_include_directories(ComponentArray
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)
target_link_libraries(ComponentArray
  INTERFACE Types
)
