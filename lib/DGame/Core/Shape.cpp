#include "Shape.h"

namespace DGame
{

  void Shape::MoveBy(const Vec2D &deltaOffset)
  {
    for (Vec2D &point : mPoints)
    {
      point = point + deltaOffset;
    }
  }
}
