#ifndef SCENES_ARCADESCENE_H_
#define SCENES_ARCADESCENE_H_

#include <memory>
#include "Scene.h"
#include "../graphics/Screen.h"
#include "../shapes/Line2D.h"
#include "../shapes/Triangle.h"
#include "../shapes/AARectangle.h"
#include "../shapes/Circle.h"
#include "../input/GameController.h"

enum eGame
{
  TETRIS = 0,
  BREAK_OUT,
  ASTEROIDS,
  PACMAN,
  NUM_GAMES
};

class ArcadeScene : public Scene
{
public:
  ArcadeScene();
  virtual void Init() override;
  virtual void Update(uint32_t dt) override;
  virtual void Draw(Screen &screen) override;
  virtual const std::string &GetSceneName() const override;

private:
  std::unique_ptr<Scene> GetScene(eGame game);

};

#endif