cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

project(DGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${DGame_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

file(GLOB_RECURSE DGame_SOURCES "Core/*.cpp")

add_library(
  ${PROJECT_NAME}
  ${DGame_SOURCES}
)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} )
