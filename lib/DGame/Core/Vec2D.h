#ifndef VEC2D_H_
#define VEC2D_H_

#include <iostream>

class Vec2D
{
public:
  static const Vec2D Zero;

  Vec2D();
  Vec2D(float x, float y);

  friend std::ostream &operator<<(std::ostream &consoleOut, const Vec2D &vec);
  friend Vec2D operator*(float scale, const Vec2D &vec);

  bool operator==(const Vec2D &vec2) const;
  bool operator!=(const Vec2D &vec2) const;

  void SetX(float x);
  void SetY(float y);
  float GetX() const;
  float GetY() const;

  Vec2D operator-() const;
  Vec2D operator*(float scale) const;
  Vec2D operator/(float scale) const;
  Vec2D &operator*=(float scale);
  Vec2D &operator/=(float scale);
  Vec2D operator+(const Vec2D &vec) const;
  Vec2D operator-(const Vec2D &vec) const;
  Vec2D operator+=(const Vec2D &vec);
  Vec2D operator-=(const Vec2D &vec);

  void Rotate(float angle, const Vec2D &aroundPoint);
  Vec2D GetUnitVec() const;
  Vec2D &Normalize();
  Vec2D ProjectOnto(const Vec2D &vec) const;
  Vec2D Reflect(const Vec2D &normal) const;
  Vec2D RotationResult(float angle, Vec2D &aroundPoint) const;

  float Magnitude2() const;
  float Magnitude() const;
  float Distance(const Vec2D &vec) const;
  float Dot(const Vec2D &vec) const;
  float AngleBetween(const Vec2D &vec) const;

private:
  float mX, mY;
};

#endif