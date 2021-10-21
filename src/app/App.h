#ifndef APP_APP_H_
#define APP_APP_H_

#include "App.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "../utils/Vec2D.h"
#include "../graphics/Color.h"
#include "../graphics/Screen.h"
#include "../scenes/ArcadeScene.h"
#include <memory>
#include <vector>
#include "../scenes/Scene.h"
#include "../input/InputController.h"
#include "../games/breakout/BreakOut.h"
#include "../scenes/GameScene.h"

struct SDL_Window;

class App
{
public:
  static App &Singleton();
  bool Init(uint32_t width, uint32_t height, uint32_t mag);
  void Run();

  inline uint32_t Width() { return mScreen.Width(); }
  inline uint32_t Height() { return mScreen.Height(); }

  void PushScene(std::unique_ptr<Scene> scene);
  void PopScene();
  Scene* TopScene();

private:
  Screen mScreen;
  SDL_Window *mnoptrWindow;

  std::vector<std::unique_ptr<Scene>> mSceneStack;

  InputController mInputController;
};

#endif
