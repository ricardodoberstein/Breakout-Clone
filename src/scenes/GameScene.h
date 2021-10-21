#ifndef SCENES_GAMESCENE_H_
#define SCENES_GAMESCENE_H_

#include "Scene.h"
#include "../games/Game.h"
#include <memory>
#include <string>

class GameScene : public Scene
{
public:
  GameScene(std::unique_ptr<Game> optrGame);

  //virtual ~GameScene() {}
  virtual void Init() override;
  virtual void Update(uint32_t dt) override;
  virtual void Draw(Screen& screen) override;
  virtual const std::string& GetSceneName() const override;

private:
  std::unique_ptr<Game> mGame;
};

#endif