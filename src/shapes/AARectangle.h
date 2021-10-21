#ifndef SHAPES_AARECTANGKE_H_
#define SHAPES_AARECTANGKE_H_

#include "Shape.h"
#include <cmath>
#include "../utils/Utils.h"
#include "../utils/Vec2D.h"

class AARectangle : public Shape
{
public:
  AARectangle();
  AARectangle(const Vec2D &topLeft, unsigned int width, unsigned int height);
  AARectangle(const Vec2D &topLeft, const Vec2D &bottomRight);

  inline void SetTopLeftPoint(const Vec2D &topLeft) { mPoints[0] = topLeft; }
  inline void SetBottomRightPoint(const Vec2D &bottomRight) { mPoints[1] = bottomRight; }

  inline Vec2D GetTopLeftPoint() const { return mPoints[0]; }
  inline Vec2D GetBottomRightPoint() const { return mPoints[1]; }

  float GetWidth() const;
  float GetHeight() const;

  void MoveTo(const Vec2D& position);

  virtual Vec2D GetCenterPoint() const override;

  bool Intersects(const AARectangle& otherRectangle) const;
  bool ContaiinsPoint(const Vec2D& point) const;

  static AARectangle Inset(const AARectangle& rect, Vec2D& inserts);

  virtual std::vector<Vec2D> GetPoints() const override;
};

#endif