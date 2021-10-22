#ifndef GAMES_BREAKOUT_BREAKOUT_H_
#define GAMES_BREAKOUT_BREAKOUT_H_

#include "../Game.h"
#include <iostream>
#include <string>
#include "Paddle.h"
#include "../../input/GameController.h"
#include "../../app/App.h"
#include "Ball.h"
#include "LevelBoundary.h"
#include "BreakoutGameLevel.h"

class BreakOut : public Game
{
public:
  virtual void Init(GameController &controller) override;
  virtual void Update(uint32_t dt) override;
  virtual void Draw(Screen &screen) override;
  virtual const std::string& GetName() override;

private:
  void ResetGame();
  const Vec2D INITIAL_BALL_VELOCITY = Vec2D(100, -100);
  Paddle mPaddle;
  Ball mBall;
  LevelBoundary mLevelBoundary;
  BreakoutGameLevel mLevel;
};

#endif