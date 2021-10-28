#ifndef MATH_VEC2D_H_
#define MATH_VEC2D_H_

#include <iostream>

namespace DGame
{
  namespace Math
  {
    class Vector2
    {
    public:
      static const Vector2 Zero;

      Vector2();
      Vector2(float x, float y);

      friend std::ostream &operator<<(std::ostream &consoleOut, const Vector2 &vec);
      friend Vector2 operator*(float scale, const Vector2 &vec);

      bool operator==(const Vector2 &vec2) const;
      bool operator!=(const Vector2 &vec2) const;

      void SetX(float x);
      void SetY(float y);
      float GetX() const;
      float GetY() const;

      Vector2 operator-() const;
      Vector2 operator*(float scale) const;
      Vector2 operator/(float scale) const;
      Vector2 &operator*=(float scale);
      Vector2 &operator/=(float scale);
      Vector2 operator+(const Vector2 &vec) const;
      Vector2 operator-(const Vector2 &vec) const;
      Vector2 operator+=(const Vector2 &vec);
      Vector2 operator-=(const Vector2 &vec);

      void Rotate(float angle, const Vector2 &aroundPoint);
      Vector2 GetUnitVec() const;
      Vector2 &Normalize();
      Vector2 ProjectOnto(const Vector2 &vec) const;
      Vector2 Reflect(const Vector2 &normal) const;
      Vector2 RotationResult(float angle, Vector2 &aroundPoint) const;

      float Magnitude2() const;
      float Magnitude() const;
      float Distance(const Vector2 &vec) const;
      float Dot(const Vector2 &vec) const;
      float AngleBetween(const Vector2 &vec) const;

    private:
      float mX, mY;
    };
  }
}

#endif