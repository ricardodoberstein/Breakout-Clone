#ifndef SHAPE_H_
#define SHAPE_H_

#include "Vec2D.h"
#include <vector>

namespace DGame
{
  class Shape
  {
  public:
    virtual Vec2D GetCenterPoint() const = 0;
    virtual ~Shape(){};
    inline virtual std::vector<Vec2D> GetPoints() const { return mPoints; }
    void MoveBy(const Vec2D &deltaOffset);

  protected:
    std::vector<Vec2D> mPoints;
  };
}

#endif