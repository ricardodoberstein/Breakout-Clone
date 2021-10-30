#ifndef INPUTCONTROLLER_H_
#define INPUTCONTROLLER_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif


#include "InputAction.h"
#include "GameController.h"

namespace DGame
{
  class InputController
  {
  public:
    InputController();
    void Init(InputAction quitAction);
    void Update(uint32_t dt);

    void SetGameController(GameController *gameController);

  private:
    InputAction mQuit;
    GameController *mnoptrCurrentController;
  };
}

#endif