#ifndef GAMECONTROLLER_H_H
#define GAMECONTROLLER_H_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif


#include "InputAction.h"
#include <vector>

namespace DGame
{
  class GameController
  {
  public:
    GameController();
    InputAction GetActionForKey(InputKey key);
    void AddInputActionForKey(const ButtonAction &ButtonAction);
    void ClearAll();

    static bool IsPressed(InputState state);
    static bool IsReleased(InputState state);
    static InputKey ActionKey();
    static InputKey CancelKey();
    static InputKey LeftKey();
    static InputKey RightKey();
    static InputKey UpKey();
    static InputKey DownKey();

    inline const MouseMovedAction &GetMouseMovedAction() { return mMouseMovedAction; }
    inline void SetMouseMovedAction(const MouseMovedAction &mouseMovedAction) { mMouseMovedAction = mouseMovedAction; }

    MouseInputAction GetMouseButtonActionForMouseButton(MouseButton button);
    void AddMouseButtonAction(const MouseButtonAction &mouseButtonAction);

    static MouseButton LeftMouseButton();
    static MouseButton RightMouseButton();

  private:
    std::vector<ButtonAction> mButtonActions;
    std::vector<MouseButtonAction> mMouseButtonActions;
    MouseMovedAction mMouseMovedAction;
  };
}

#endif