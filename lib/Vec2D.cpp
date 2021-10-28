#include "Vec2D.h"
#include "Utils.h"
#include <cassert>
#include <cmath>

const Vec2D Vec2D::Zero;

Vec2D::Vec2D(): Vec2D(0, 0) 
{
  
}

Vec2D::Vec2D(float x, float y): mX(x), mY(y)
{
  
}

std::ostream &operator<<(std::ostream &consoleOut, const Vec2D &vec)
{
  consoleOut << "X: " << vec.mX << " Y: " << vec.mY << std::endl;
  return consoleOut;
}

bool Vec2D::operator==(const Vec2D &vec2) const
{
  return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);
}

bool Vec2D::operator!=(const Vec2D &vec2) const
{
  return !(*this == vec2);
}

void Vec2D::SetX(float x)
{
  mX = x;
}

void Vec2D::SetY(float y) 
{
  mY = y;
}

float Vec2D::GetX() const
{
  return mX;
}

float Vec2D::GetY() const
{
  return mY;
}

Vec2D Vec2D::operator-() const
{
  return Vec2D(-mX, -mY);
}

Vec2D Vec2D::operator*(float scale) const
{
  return Vec2D(scale * mX, scale * mY);
}

Vec2D Vec2D::operator/(float scale) const
{
  assert(fabsf(scale) > EPSILON);

  return Vec2D(mX / scale, mY / scale);
}

Vec2D &Vec2D::operator*=(float scale)
{
  *this = *this * scale;
  return *this;
}

Vec2D &Vec2D::operator/=(float scale)
{
  assert(fabsf(scale) > EPSILON);

  *this = *this / scale;
  return *this;
}

Vec2D operator*(float scale, const Vec2D &vec)
{
  return vec * scale;
}

Vec2D Vec2D::operator+(const Vec2D &vec) const
{
  return Vec2D(mX + vec.mX, mY + vec.mY);
}
Vec2D Vec2D::operator-(const Vec2D &vec) const
{
  return Vec2D(mX - vec.mX, mY - vec.mY);
}

Vec2D Vec2D::operator+=(const Vec2D &vec)
{
  *this = *this + vec;
  return *this;
}

Vec2D Vec2D::operator-=(const Vec2D &vec)
{
  *this = *this - vec;
  return *this;
}

float Vec2D::Magnitude2() const
{
  return Dot(*this);
}

float Vec2D::Magnitude() const
{
  return sqrt(Magnitude2());
}

Vec2D Vec2D::GetUnitVec() const
{
  float magnitude = Magnitude();

  if (magnitude > EPSILON)
  {
    return *this / magnitude;
  }

  return Vec2D::Zero;
}

Vec2D &Vec2D::Normalize()
{
  float magnitude = Magnitude();

  if (magnitude > EPSILON)
  {
    *this /= magnitude;
  }

  return *this;
}

float Vec2D::Distance(const Vec2D &vec) const
{
  return (vec - *this).Magnitude();
}

float Vec2D::Dot(const Vec2D &vec) const
{
  return mX * vec.mX + mY * vec.mY;
}

Vec2D Vec2D::ProjectOnto(const Vec2D &vec) const
{
  Vec2D unitVec = vec.GetUnitVec();

  float dot = Dot(unitVec);

  return unitVec * dot;
}

float Vec2D::AngleBetween(const Vec2D &vec) const
{
  return acosf(GetUnitVec().Dot(vec.GetUnitVec()));
}

Vec2D Vec2D::Reflect(const Vec2D &normal) const
{
  return *this - 2 * ProjectOnto(normal);
}

void Vec2D::Rotate(float angle, const Vec2D &aroundPoint)
{
  float cosine = cosf(angle);
  float sine = sinf(angle);

  Vec2D thisVec(mX, mY);

  thisVec -= aroundPoint;

  float xRot = thisVec.mX * cosine - thisVec.mY * sine;
  float yRot = thisVec.mX * sine + thisVec.mY * cosine;

  Vec2D rot = Vec2D(xRot, yRot);

  *this = rot + aroundPoint;
}
Vec2D Vec2D::RotationResult(float angle, Vec2D &aroundPoint) const
{
  float cosine = cosf(angle);
  float sine = sinf(angle);

  Vec2D thisVec(mX, mY);

  thisVec -= aroundPoint;

  float xRot = thisVec.mX * cosine - thisVec.mY * sine;
  float yRot = thisVec.mX * sine + thisVec.mY * cosine;

  Vec2D rot = Vec2D(xRot, yRot);

  return rot + aroundPoint;
}
