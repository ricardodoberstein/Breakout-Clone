#ifndef SCENE_H_
#define SCENE_H_

#include <string>
#include <stdint.h>
#include "Screen.h"
#include "GameController.h"

namespace DGame
{
  class Scene
  {
  public:
    //virtual ~Scene();
    virtual void Init() = 0;
    virtual void Update(uint32_t dt) = 0;
    virtual void Draw(Screen &screen) = 0;
    virtual const std::string &GetSceneName() const = 0;

    inline GameController *GetGameController() { return &mGameController; }

  protected:
    GameController mGameController;
  };
}

#endif
