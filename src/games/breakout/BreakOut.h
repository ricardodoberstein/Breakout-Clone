#ifndef GAMES_BREAKOUT_BREAKOUT_H_
#define GAMES_BREAKOUT_BREAKOUT_H_

#include "../Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "LevelBoundary.h"
#include "BreakoutGameLevel.h"
#include <vector>

class BreakOut : public Game
{
public:
  virtual void Init(GameController &controller) override;
  virtual void Update(uint32_t dt) override;
  virtual void Draw(Screen &screen) override;
  virtual const std::string& GetName() override;

private:
  void ResetGame();

  BreakoutGameLevel& GetCurrentLevel();

  const Vec2D INITIAL_BALL_VELOCITY = Vec2D(100, -100);
  Paddle mPaddle;
  Ball mBall;
  LevelBoundary mLevelBoundary;
  std::vector<BreakoutGameLevel> mLevels;
  size_t mCurrentLevel;
};

#endif