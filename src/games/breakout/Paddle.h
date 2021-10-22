#ifndef GAMES_BREAKOUT_PADDLE_H_
#define GAMES_BREAKOUT_PADDLE_H_

#include "Excluder.h"
#include "../../shapes/AARectangle.h"
#include <stdint.h>
#include "../../graphics/Screen.h"
#include "../../utils/Utils.h"
#include "BoundaryEdge.h"
#include "Ball.h"

enum PaddleDirection
{
  LEFT = 1 << 0,
  RIGHT = 1 << 1
};

class Paddle : public Excluder
{
public:
  static const uint32_t PADDLE_WIDTH = 50;
  static const uint32_t PADDLE_HEIGHT = 10;
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
  const float VELOCITY = 100.0f;
  const float CORNER_BOUNCE_AMT = 0.2f;
};

#endif
