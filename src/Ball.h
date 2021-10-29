#ifndef BALL_H_
#define BALL_H_

#include "DGame/DGame.h"
#include <stdint.h>

class Ball
{
public:
  Ball();
  Ball(const Vec2D &pos, float radius);

  void Update(uint32_t dt);
  void Draw(Screen &screen);
  void MakeFlushWithEdge(const BoundaryEdge &edge, Vec2D &pointOnEdge, bool limitToEdge);
  void MoveTo(const Vec2D &point);

  void Bounce(const BoundaryEdge &edge);

  inline const AARectangle GetBoundingRect() const { return mBBox; }
  inline void Stop() { mVelocity = Vec2D::Zero; }
  inline void SetVelocity(const Vec2D &vel) { mVelocity = vel; }
  inline Vec2D GetVelocity() const { return mVelocity; }
  inline float GetRadius() const { return mBBox.GetWidth() / 2.0f; }
  inline Vec2D GetPosition() const { return mBBox.GetCenterPoint(); }
  inline void IncreaseVelocity(float multipler) { mVelocityMultipler += multipler; }
  inline void DecreaseVelocity(float multipler) { mVelocityMultipler -= multipler; }
  inline void ResetVelocity() { mVelocityMultipler = 1.0f; }

private:
  AARectangle mBBox;
  Vec2D mVelocity;
  float mVelocityMultipler;

  static const float RADIUS;
};

#endif
