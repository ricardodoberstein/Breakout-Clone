#include "Paddle.h"

void Paddle::Init(const AARectangle &rect, const AARectangle& boundary)
{
  Excluder::Init(rect);
  mBoundary = boundary;
  mDirection = 0;
}

void Paddle::Update(uint32_t dt)
{
  if (mDirection != 0)
  {
    Vec2D dir;
    if((mDirection & PaddleDirection::LEFT) == PaddleDirection::LEFT && (mDirection & PaddleDirection::RIGHT) == PaddleDirection::RIGHT)
    {
      dir = Vec2D::Zero;
    }
    else if (mDirection == PaddleDirection::LEFT)
    {
      dir = LEFT_DIR;
    }
    else
    {
      dir = RIGHT_DIR;
    }

    Vec2D dx = dir * VELOCITY * MillisecondsToSeconds(dt);

    MoveBy(dx);

    const AARectangle& aaRect = GetAARectangle();

    if (IsGreaterThanOrEqual(mBoundary.GetTopLeftPoint().GetX(), aaRect.GetTopLeftPoint().GetX()))
    {
      MoveTo(Vec2D(mBoundary.GetTopLeftPoint().GetX(), aaRect.GetTopLeftPoint().GetY()));
    }
    else if (IsGreaterThanOrEqual(aaRect.GetBottomRightPoint().GetX(), mBoundary.GetBottomRightPoint().GetX()))
    {
      MoveTo(Vec2D(mBoundary.GetBottomRightPoint().GetX() - aaRect.GetWidth(), aaRect.GetTopLeftPoint().GetY()));
    }
  }
}

void Paddle::Draw(Screen &screen)
{
  screen.Draw(GetAARectangle(), Color::Blue(), true, Color::Blue());
}
