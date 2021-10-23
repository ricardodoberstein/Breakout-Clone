#include "BreakOut.h"
#include <iostream>

void BreakOut::Init(GameController &controller)
{
  controller.ClearAll();
  ResetGame();
  ButtonAction leftKeyAction;
  leftKeyAction.key = GameController::LeftKey();
  leftKeyAction.action = [this](uint32_t dt, InputState state)
  {
    if (GameController::IsPressed(state))
    {
      mPaddle.SetMovemenetDirection(PaddleDirection::LEFT);
    }
    else
    {
      mPaddle.UnsetMovementDirection(PaddleDirection::LEFT);
    }
  };

  controller.AddInputActionForKey(leftKeyAction);

  ButtonAction rightKeyAction;
  rightKeyAction.key = GameController::RightKey();
  rightKeyAction.action = [this](uint32_t dt, InputState state)
  {
    if (GameController::IsPressed(state))
    {
      mPaddle.SetMovemenetDirection(PaddleDirection::RIGHT);
    }
    else
    {
      mPaddle.UnsetMovementDirection(PaddleDirection::RIGHT);
    }
  };

  controller.AddInputActionForKey(rightKeyAction);
}

void BreakOut::Update(uint32_t dt)
{
  mBall.Update(dt);
  mPaddle.Update(dt, mBall);

  BoundaryEdge edge;

  if (mPaddle.Bounce(mBall))
  {
    return;
  }

  if (mLevelBoundary.HasCollided(mBall, edge))
  {
    mBall.Bounce(edge);
    return;
  }

  GetCurrentLevel().Update(dt, mBall);
}

void BreakOut::Draw(Screen &screen)
{
  mBall.Draw(screen);
  mPaddle.Draw(screen);
  GetCurrentLevel().Draw(screen);
  screen.Draw(mLevelBoundary.GetAARectangle(), Color::White());
}

const std::string& BreakOut::GetName()
{
  static std::string name = "BreakOut";
  return name;
}

void BreakOut::ResetGame()
{
  mLevels = BreakoutGameLevel::LoadLevelsFromFile(App::GetBasePath() + "assets/BreakoutLevels.txt");
  mCurrentLevel = 0;
  
  AARectangle paddleRect = {Vec2D(App::Singleton().Width()/2 - Paddle::PADDLE_WIDTH/2, App::Singleton().Height() - 3*30), Paddle::PADDLE_WIDTH, Paddle::PADDLE_HEIGHT};
  AARectangle levelBoundary = { Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height() };
  
  mLevelBoundary = {levelBoundary};

  mPaddle.Init(paddleRect, levelBoundary);
  mBall.MoveTo(Vec2D(App::Singleton().Width()/2, App::Singleton().Height() * 0.75f));
  mBall.SetVelocity(INITIAL_BALL_VELOCITY);
}

BreakoutGameLevel& BreakOut::GetCurrentLevel()
{
  return mLevels[mCurrentLevel];
}