#ifndef GAMES_BREAKOUT_BREAKOUT_H_
#define GAMES_BREAKOUT_BREAKOUT_H_

#include "../Game.h"
#include <iostream>
#include <string>
#include "Paddle.h"
#include "../../input/GameController.h"
#include "../../app/App.h"

class BreakOut : public Game
{
public:
  virtual void Init(GameController &controller) override;
  virtual void Update(uint32_t dt) override;
  virtual void Draw(Screen &screen) override;
  virtual std::string GetName() override;

private:
  void ResetGame();
  Paddle mPaddle;
};

#endif