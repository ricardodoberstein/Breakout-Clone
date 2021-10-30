cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

project(Breakout)
set(BIN_DIR ${Breakout_SOURCE_DIR}/bin)

set(SDL2_INCLUDE_DIR "C:/SDL2/Development Libraries/SDL2-2.0.16/include")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

file(GLOB_RECURSE Breakout-Clone_SOURCES "src/*.cpp")

add_executable(
  ${PROJECT_NAME}
  ${Breakout-Clone_SOURCES}
)

add_subdirectory(lib/DGame src)

target_include_directories(
  ${PROJECT_NAME} 
  PUBLIC lib
  PUBLIC lib/DGame
)

file(COPY src/assets/BreakoutLevels.txt DESTINATION assets)
file(COPY src/assets/ArcadeFont.txt DESTINATION assets)
file(COPY src/assets/ArcadeFont.bmp DESTINATION assets)

target_link_libraries(${PROJECT_NAME} DGame ${SDL2_LIBRARY})

install(TARGETS Breakout RUNTIME DESTINATION ${BIN_DIR})