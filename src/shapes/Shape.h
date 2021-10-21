#ifndef SHAPES_SHAPE_H_
#define SHAPES_SHAPE_H_

#include "../utils/Vec2D.h"
#include <vector>

class Shape
{
public:
  virtual Vec2D GetCenterPoint() const = 0;
  virtual ~Shape() {};
  inline virtual std::vector<Vec2D> GetPoints() const { return mPoints; }
  void MoveBy(const Vec2D& deltaOffset);

protected:
  std::vector<Vec2D> mPoints;
};

#endif