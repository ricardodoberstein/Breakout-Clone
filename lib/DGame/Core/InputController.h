#ifndef INPUTCONTROLLER_H_
#define INPUTCONTROLLER_H_

#include "InputAction.h"
#include "GameController.h"
#include "SDL.h"

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