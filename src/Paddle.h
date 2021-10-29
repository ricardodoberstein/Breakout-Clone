#ifndef PADDLE_H_
#define PADDLE_H_

#include <stdint.h>
#include "Ball.h"
#include "DGame/DGame.h"

using namespace DGame;

enum PaddleDirection
{
  LEFT = 1 << 0,
  RIGHT = 1 << 1
};

class Paddle : public Excluder
{
public:
  static const uint32_t PADDLE_WIDTH = 30;
  static const uint32_t PADDLE_HEIGHT = 4;
  void Init(const AARectangle &rect, const AARectangle &boundary);
  void Update(uint32_t dt, Ball &ball);
  void Draw(Screen &screen);

  bool Bounce(Ball &ball);

  inline void SetMovemenetDirection(PaddleDirection dir) { mDirection |= dir; }
  inline void UnsetMovementDirection(PaddleDirection dir) { mDirection &= ~dir; }
  inline void StopMovement() { mDirection = 0; }
  inline bool IsMovingLeft() const { return mDirection == PaddleDirection::LEFT; }
  inline bool IsMovingRight() const { return mDirection == PaddleDirection::RIGHT; }

private:
  uint32_t mDirection;
  AARectangle mBoundary;
  const float VELOCITY = 150.0f;
  const float CORNER_BOUNCE_AMT = 0.2f;
};

#endif
