#include "Line2D.h"
#include <cmath>
#include "Utils.h"

namespace DGame
{
  Line2D::Line2D() : Line2D(Vec2D::Zero, Vec2D::Zero)
  {
  }

  Line2D::Line2D(float x0, float y0, float x1, float y1) : Line2D(Vec2D(x0, y0), Vec2D(x1, y1))
  {
  }

  Line2D::Line2D(const Vec2D &p0, const Vec2D &p1) : mP0(p0), mP1(p1)
  {
  }

  bool Line2D::operator==(const Line2D &line) const
  {
    return line.GetP0() == mP0 && line.GetP1() == mP1;
  }

  float Line2D::MinDistanceFrom(const Vec2D &p, bool limitToSegment) const
  {
    return p.Distance(ClosestPoint(p, limitToSegment));
  }

  Vec2D Line2D::ClosestPoint(const Vec2D &p, bool limitToSegment) const
  {
    Vec2D p0ToP = p - mP0;
    Vec2D p0ToP1 = mP1 - mP0;
    float l2 = p0ToP1.Magnitude2();
    float dot = p0ToP.Dot(p0ToP1);
    float t = dot / l2;

    if (limitToSegment)
    {
      t = std::fmax(0, std::fmin(1.0f, t));
    }

    return mP0 + p0ToP1 * t;
  }

  Vec2D Line2D::MidPoint() const
  {
    return Vec2D((mP0.GetX() + mP1.GetX()) / 2.0f, (mP0.GetY(), mP1.GetY()) / 2.0f);
  }

  float Line2D::Slope() const
  {
    float dx = mP1.GetX() - mP0.GetX();
    if (fabsf(dx) < EPSILON)
    {
      return 0;
    }

    float dy = mP1.GetY() - mP0.GetY();

    return dy / dx;
  }

  float Line2D::Length() const
  {
    return mP1.Distance(mP0);
  }
  
}
