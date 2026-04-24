add_library(EntityManager STATIC)

target_sources(EntityManager
  PRIVATE
    Private/EntityManagerImpl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS Public
    FILES
      Public/EntityManager.hpp
)

target_include_directories(EntityManager
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Public
)

find_package(raylib REQUIRED)

target_link_libraries(EntityManager
  PUBLIC raylib 
  PUBLIC Types
)

target_compile_options(EntityManager PRIVATE -mcmodel=medium)
