#include "BreakOut.h"

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
  mPaddle.Update(dt);
}

void BreakOut::Draw(Screen &screen)
{
  mPaddle.Draw(screen);
}

std::string BreakOut::GetName()
{
  static std::string name = "BreakOut";
  return name;
}

void BreakOut::ResetGame()
{
  AARectangle paddleRect = {Vec2D(App::Singleton().Width()/2 - Paddle::PADDLE_WIDTH/2, App::Singleton().Height() - 3*30), Paddle::PADDLE_WIDTH, Paddle::PADDLE_HEIGHT};
  AARectangle levelBoundary = { Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height() };
  mPaddle.Init(paddleRect, levelBoundary);
}
