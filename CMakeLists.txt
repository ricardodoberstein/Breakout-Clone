cmake_minimum_required(VERSION 3.5)

project(Arcade)

add_executable(
  ${PROJECT_NAME}
  src/ArcadeApp.cpp
  src/app/App.cpp
  src/app/App.h
  src/games/Game.h
  src/games/breakout/BoundaryEdge.h
  src/games/breakout/BreakOut.cpp
  src/games/breakout/BreakOut.h
  src/games/breakout/Excluder.cpp
  src/games/breakout/Excluder.h
  src/games/breakout/Paddle.cpp
  src/games/breakout/Paddle.h
  src/graphics/Color.cpp
  src/graphics/Color.h
  src/graphics/Screen.cpp
  src/graphics/Screen.h
  src/graphics/ScreenBuffer.cpp
  src/graphics/ScreenBuffer.h
  src/input/GameController.cpp
  src/input/GameController.h
  src/input/InputAction.h
  src/input/InputController.cpp
  src/input/InputController.h
  src/scenes/ArcadeScene.cpp
  src/scenes/ArcadeScene.h
  src/scenes/GameScene.cpp
  src/scenes/GameScene.h
  src/scenes/Scene.h
  src/shapes/AARectangle.cpp
  src/shapes/AARectangle.h
  src/shapes/Circle.cpp
  src/shapes/Circle.h
  src/shapes/Line2D.cpp
  src/shapes/Line2D.h
  src/shapes/Shape.cpp
  src/shapes/Shape.h
  src/shapes/Triangle.cpp
  src/shapes/Triangle.h
  src/utils/FileCommandLoader.cpp
  src/utils/FileCommandLoader.h
  src/utils/Utils.cpp
  src/utils/Utils.h
  src/utils/Vec2D.cpp
  src/utils/Vec2D.h
)

target_link_libraries(${PROJECT_NAME} SDL2)