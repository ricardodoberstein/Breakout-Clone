#include "Vector2.h"
#include "../Utils.h"
#include <cassert>
#include <cmath>

namespace DGame
{
  namespace Math
  {
    const DGame::Math::Vector2 DGame::Math::Vector2::Zero;

    Vector2::Vector2() : Vector2(0, 0)
    {
    }

    Vector2::Vector2(float x, float y) : mX(x), mY(y)
    {
    }

    std::ostream &operator<<(std::ostream &consoleOut, const Vector2 &vec)
    {
      consoleOut << "X: " << vec.mX << " Y: " << vec.mY << std::endl;
      return consoleOut;
    }

    bool Vector2::operator==(const Vector2 &vec2) const
    {
      return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);
    }

    bool Vector2::operator!=(const Vector2 &vec2) const
    {
      return !(*this == vec2);
    }

    void Vector2::SetX(float x)
    {
      mX = x;
    }

    void Vector2::SetY(float y)
    {
      mY = y;
    }

    float Vector2::GetX() const
    {
      return mX;
    }

    float Vector2::GetY() const
    {
      return mY;
    }

    Vector2 Vector2::operator-() const
    {
      return Vector2(-mX, -mY);
    }

    Vector2 Vector2::operator*(float scale) const
    {
      return Vector2(scale * mX, scale * mY);
    }

    Vector2 Vector2::operator/(float scale) const
    {
      assert(fabsf(scale) > EPSILON);

      return Vector2(mX / scale, mY / scale);
    }

    Vector2 &Vector2::operator*=(float scale)
    {
      *this = *this * scale;
      return *this;
    }

    Vector2 &Vector2::operator/=(float scale)
    {
      assert(fabsf(scale) > EPSILON);

      *this = *this / scale;
      return *this;
    }

    Vector2 operator*(float scale, const Vector2 &vec)
    {
      return vec * scale;
    }

    Vector2 Vector2::operator+(const Vector2 &vec) const
    {
      return Vector2(mX + vec.mX, mY + vec.mY);
    }
    Vector2 Vector2::operator-(const Vector2 &vec) const
    {
      return Vector2(mX - vec.mX, mY - vec.mY);
    }

    Vector2 Vector2::operator+=(const Vector2 &vec)
    {
      *this = *this + vec;
      return *this;
    }

    Vector2 Vector2::operator-=(const Vector2 &vec)
    {
      *this = *this - vec;
      return *this;
    }

    float Vector2::Magnitude2() const
    {
      return Dot(*this);
    }

    float Vector2::Magnitude() const
    {
      return sqrt(Magnitude2());
    }

    Vector2 Vector2::GetUnitVec() const
    {
      float magnitude = Magnitude();

      if (magnitude > EPSILON)
      {
        return *this / magnitude;
      }

      return Vector2::Zero;
    }

    Vector2 &Vector2::Normalize()
    {
      float magnitude = Magnitude();

      if (magnitude > EPSILON)
      {
        *this /= magnitude;
      }

      return *this;
    }

    float Vector2::Distance(const Vector2 &vec) const
    {
      return (vec - *this).Magnitude();
    }

    float Vector2::Dot(const Vector2 &vec) const
    {
      return mX * vec.mX + mY * vec.mY;
    }

    Vector2 Vector2::ProjectOnto(const Vector2 &vec) const
    {
      Vector2 unitVec = vec.GetUnitVec();

      float dot = Dot(unitVec);

      return unitVec * dot;
    }

    float Vector2::AngleBetween(const Vector2 &vec) const
    {
      return acosf(GetUnitVec().Dot(vec.GetUnitVec()));
    }

    Vector2 Vector2::Reflect(const Vector2 &normal) const
    {
      return *this - 2 * ProjectOnto(normal);
    }

    void Vector2::Rotate(float angle, const Vector2 &aroundPoint)
    {
      float cosine = cosf(angle);
      float sine = sinf(angle);

      Vector2 thisVec(mX, mY);

      thisVec -= aroundPoint;

      float xRot = thisVec.mX * cosine - thisVec.mY * sine;
      float yRot = thisVec.mX * sine + thisVec.mY * cosine;

      Vector2 rot = Vector2(xRot, yRot);

      *this = rot + aroundPoint;
    }
    Vector2 Vector2::RotationResult(float angle, Vector2 &aroundPoint) const
    {
      float cosine = cosf(angle);
      float sine = sinf(angle);

      Vector2 thisVec(mX, mY);

      thisVec -= aroundPoint;

      float xRot = thisVec.mX * cosine - thisVec.mY * sine;
      float yRot = thisVec.mX * sine + thisVec.mY * cosine;

      Vector2 rot = Vector2(xRot, yRot);

      return rot + aroundPoint;
    }

  }
}