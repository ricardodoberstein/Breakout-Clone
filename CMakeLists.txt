cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)

project(Arcade)

add_executable(
  ${PROJECT_NAME}
  src/main.cpp
  src/BreakOut.cpp
  src/BreakOut.h
  src/Paddle.cpp
  src/Paddle.h
  src/Ball.h
  src/Ball.cpp
  src/LevelBoundary.h
  src/LevelBoundary.cpp
  src/Block.h
  src/Block.cpp
  src/BreakoutGameLevel.h
  src/BreakoutGameLevel.cpp
)

add_subdirectory(lib src)

target_include_directories(
  ${PROJECT_NAME} 
  PUBLIC lib
)

file(COPY src/assets/BreakoutLevels.txt DESTINATION assets)
file(COPY src/assets/ArcadeFont.txt DESTINATION assets)
file(COPY src/assets/ArcadeFont.bmp DESTINATION assets)

target_link_libraries(${PROJECT_NAME} lib)