add_library(SystemManager INTERFACE)
target_sources(SystemManager
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/SystemManager.hpp
)
target_include_directories(SystemManager
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)
target_link_libraries(SystemManager
  INTERFACE Types
  INTERFACE Utils
)
