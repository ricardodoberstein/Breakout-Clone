#ifndef ARCADESCENE_H_
#define ARCADESCENE_H_

#include <memory>
#include "Scene.h"
#include "Screen.h"
#include "Line2D.h"
#include "Triangle.h"
#include "AARectangle.h"
#include "Circle.h"
#include "GameController.h"
#include "BMPImage.h"
#include "App.h"
#include "BitmapFont.h"

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