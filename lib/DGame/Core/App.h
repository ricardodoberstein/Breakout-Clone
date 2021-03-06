#ifndef APP_H_
#define APP_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "App.h"
#include <iostream>
#include "Vec2D.h"
#include "Color.h"
#include "Screen.h"
#include <memory>
#include <vector>
#include "Scene.h"
#include "InputController.h"
#include "GameScene.h"
#include "BitmapFont.h"

namespace DGame
{
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
    Scene *TopScene();

    inline const BitmapFont &GetFont() const { return mFont; }

  private:
    Screen mScreen;
    SDL_Window *mnoptrWindow;

    std::vector<std::unique_ptr<Scene>> mSceneStack;

    InputController mInputController;

    BitmapFont mFont;
  };
}

#endif
