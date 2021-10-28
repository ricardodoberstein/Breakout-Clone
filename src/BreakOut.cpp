#include "BreakOut.h"
#include <iostream>
#include "Path.h"

void BreakOut::Init(GameController &controller)
{
  controller.ClearAll();

  ResetGame();

  ButtonAction serveAction;
  serveAction.key = GameController::ActionKey();
  serveAction.action = [this](uint32_t dt, InputState state)
  {
    if (mGameState == IN_SERVE)
    {
      if (GameController::IsPressed(state))
      {
        mGameState = IN_PLAY;

        if (mPaddle.IsMovingLeft())
        {
          mBall.SetVelocity(Vec2D(-INITIAL_BALL_SPEED, -INITIAL_BALL_SPEED));
        }
        else
        {
          mBall.SetVelocity(Vec2D(INITIAL_BALL_SPEED, -INITIAL_BALL_SPEED));
        }
      }
    }
    else if (mGameState == IN_GAME_OVER)
    {
      if (GameController::IsPressed(state))
      {
        ResetGame();
      }
    }
  };

  controller.AddInputActionForKey(serveAction);

  ButtonAction leftKeyAction;
  leftKeyAction.key = GameController::LeftKey();
  leftKeyAction.action = [this](uint32_t dt, InputState state)
  {
    if (mGameState == IN_PLAY || mGameState == IN_SERVE)
    {
      if (GameController::IsPressed(state))
      {
        mPaddle.SetMovemenetDirection(PaddleDirection::LEFT);
      }
      else
      {
        mPaddle.UnsetMovementDirection(PaddleDirection::LEFT);
      }
    }
  };

  controller.AddInputActionForKey(leftKeyAction);

  ButtonAction rightKeyAction;
  rightKeyAction.key = GameController::RightKey();
  rightKeyAction.action = [this](uint32_t dt, InputState state)
  {
    if (mGameState == IN_PLAY || mGameState == IN_SERVE)
    {
      if (GameController::IsPressed(state))
      {
        mPaddle.SetMovemenetDirection(PaddleDirection::RIGHT);
      }
      else
      {
        mPaddle.UnsetMovementDirection(PaddleDirection::RIGHT);
      }
    }
  };

  controller.AddInputActionForKey(rightKeyAction);
}

void BreakOut::Update(uint32_t dt)
{
  if (mGameState == IN_SERVE)
  {
    mPaddle.Update(dt, mBall);
    SetToServeState();
  }
  else if (mGameState == IN_PLAY)
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

    if (IsBallPassedCutoffY())
    {
      ReduceLifeByOne();
      if (!IsGameOver())
      {
        SetToServeState();
      }
      else
      {
        mGameState = IN_GAME_OVER;
      }
    }
    else if (GetCurrentLevel().IsLevelComplete())
    {
      mCurrentLevel = (mCurrentLevel + 1) % mLevels.size();
      ResetGame(mCurrentLevel);
    }
  }
}

void BreakOut::Draw(Screen &screen)
{
  mBall.Draw(screen);
  mPaddle.Draw(screen);
  GetCurrentLevel().Draw(screen);
  screen.Draw(mLevelBoundary.GetAARectangle(), Color::White());

  Circle lifeCircle = {Vec2D(7, App::Singleton().Height() - 10), 5};

  for (int i = 0; i < mLives; ++i)
  {
    screen.Draw(lifeCircle, Color::Red(), true, Color::Red());
    lifeCircle.MoveBy(Vec2D(17, 0));
  }

  std::string points = std::to_string(mPoints);
  Vec2D gameTopLeft = mLevelBoundary.GetAARectangle().GetTopLeftPoint();
  screen.Draw(App::Singleton().GetFont(), points, Vec2D(gameTopLeft.GetX() + 3, gameTopLeft.GetY() + 3), Color::White());

  if (mGameState == IN_GAME_OVER)
  {
    std::string gameOver = "Game Over";
    BitmapFont font = App::Singleton().GetFont();
    Size size = font.GetSizeOf(gameOver);
    screen.Draw(App::Singleton().GetFont(), gameOver, Vec2D(App::Singleton().Width() / 2 - (size.width / 2), App::Singleton().Height() / 2 - (size.height - 2)), Color::White());
  }
}

const std::string &BreakOut::GetName()
{
  static std::string name = "BreakOut";
  return name;
}

void BreakOut::ResetGame(size_t toLevel)
{
  if (toLevel == 0)
  {
    mPoints = 0;
    mHits = 0;
    mOrangeContact = false;
    mRedContact = false;
    mBall.ResetVelocity();
    mLives = NUM_LIVES;
  }

  mLevels = BreakoutGameLevel::LoadLevelsFromFile(Path::GetBasePath() + "assets/BreakoutLevels.txt");

  if (GetCurrentLevel().onBlockDestroyed == nullptr)
  {
    GetCurrentLevel().onBlockDestroyed = [&](const Block &block)
    {
      mHits += 1;

      if (mHits == 4)
      {
        mBall.IncreaseVelocity(0.2f);
      }

      if (mOrangeContact == false)
      {
        if (block.GetFillColor().GetRed() == 193 && block.GetFillColor().GetGreen() == 133 && block.GetFillColor().GetBlue() == 10)
        {
          mBall.IncreaseVelocity(0.2f);
          mOrangeContact = true;
        }
      }

      if (mRedContact == false)
      {
        if (block.GetFillColor().GetRed() == 163 && block.GetFillColor().GetGreen() == 30 && block.GetFillColor().GetBlue() == 10)
        {
          mBall.IncreaseVelocity(0.2f);
          mRedContact = true;
        }
      }

      mPoints += block.GetPoints();
    };
  }

  mYCutoff = App::Singleton().Height() - 2 * Paddle::PADDLE_HEIGHT;
  mCurrentLevel = toLevel;

  AARectangle paddleRect = {Vec2D(App::Singleton().Width() / 2 - Paddle::PADDLE_WIDTH / 2, App::Singleton().Height() - 30), Paddle::PADDLE_WIDTH, Paddle::PADDLE_HEIGHT};

  float x_position = (App::Singleton().Width() / 2) - 122;
  float y_position = 0;
  AARectangle levelBoundary = {Vec2D(x_position, y_position), 244, 288};

  mLevelBoundary = {levelBoundary};

  mPaddle.Init(paddleRect, levelBoundary);
  mBall.MoveTo(Vec2D(App::Singleton().Width() / 2, App::Singleton().Height() * 0.75f));

  SetToServeState();
}

BreakoutGameLevel &BreakOut::GetCurrentLevel()
{
  return mLevels[mCurrentLevel];
}

void BreakOut::SetToServeState()
{
  mGameState = IN_SERVE;
  mBall.Stop();

  mBall.MoveTo(Vec2D(mPaddle.GetAARectangle().GetCenterPoint().GetX(), mPaddle.GetAARectangle().GetTopLeftPoint().GetY() - mBall.GetRadius()));
}

bool BreakOut::IsBallPassedCutoffY() const
{
  return mBall.GetPosition().GetY() > mYCutoff;
}

void BreakOut::ReduceLifeByOne()
{
  if (mLives >= 0)
  {
    --mLives;
  }
}