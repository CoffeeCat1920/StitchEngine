add_library(SystemManager STATIC)

target_sources(SystemManager
  PRIVATE
    Private/SystemManager.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/SystemManager.hpp
)
target_include_directories(SystemManager
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)
target_link_libraries(SystemManager
  PUBLIC Types
  PUBLIC Utils
)
