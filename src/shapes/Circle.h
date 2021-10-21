#ifndef SHAPES_CIRCLE_H_
#define SHAPES_CIRCLE_H_

#include "Shape.h"
#include "../utils/Vec2D.h"
#include "../utils/Utils.h"

class Circle : public Shape
{
public:
  Circle();
  Circle(const Vec2D &center, float radius);

  inline virtual Vec2D GetCenterPoint() const override { return mPoints[0]; }
  inline float GetRadius() const { return mRadius; }
  inline void SetRadius(float radius) { mRadius = radius; }
  inline void MoveTo(const Vec2D& position) { mPoints[0] = position; }

  bool Insersects(const Circle &otherCircle) const;
  bool ContainsPoint(const Vec2D& point) const;

private:
  float mRadius;
};

#endif