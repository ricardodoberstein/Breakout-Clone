#ifndef GAMES_BREAKOUT_LEVELBOUNDARY_H_
#define GAMES_BREAKOUT_LEVELBOUNDARY_H_

#include "Excluder.h"
#include "../../shapes/AARectangle.h"
#include "Ball.h"
#include "BoundaryEdge.h"

class LevelBoundary
{
public:
  LevelBoundary(){}
  LevelBoundary(const AARectangle &boundary);
  bool HasCollided(const Ball &ball, BoundaryEdge &edge);

  inline const AARectangle &GetAARectangle() { return mIncluder.GetAARectangle(); }

private:
  bool HasCollidedWithEdge(const Ball& ball, const BoundaryEdge& edge) const;
  Excluder mIncluder;
};

#endif