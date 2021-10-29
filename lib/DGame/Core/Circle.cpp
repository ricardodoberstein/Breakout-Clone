#include "Circle.h"

namespace DGame
{
  Circle::Circle() : Circle(Vec2D::Zero, 0)
  {
  }

  Circle::Circle(const Vec2D &center, float radius) : mRadius(radius)
  {
    mPoints.push_back(center);
  }

  bool Circle::Insersects(const Circle &otherCircle) const
  {
    return GetCenterPoint().Distance(otherCircle.GetCenterPoint()) < (mRadius + otherCircle.mRadius);
  }

  bool Circle::ContainsPoint(const Vec2D &point) const
  {
    return IsLessThanOrEqual(GetCenterPoint().Distance(point), mRadius);
  }
}
