#ifndef BLOCK_H_
#define BLOCK_H_

#include "Excluder.h"
#include "Color.h"
#include "Ball.h"
#include "Screen.h"
#include "BoundaryEdge.h"

class Block : public Excluder
{
public:
  static const int UNBREAKABLE = -1;

  Block();
  void Init(const AARectangle &rect, int hp, const Color &outlineColor, const Color &fillColor, const int &points = 1);
  void Draw(Screen &screen);
  void Bounce(Ball &bounce, const BoundaryEdge &edge);

  void ReduceHP();
  inline int GetHP() const { return mHp; }
  inline int GetPoints() const { return mPoints; }
  inline bool IsDestroyed() const { return mHp == 0; }
  inline const Color &GetOutlineColor() const { return mOutlineColor; }
  inline const Color &GetFillColor() const { return mFillColor; }

private:
  Color mOutlineColor;
  Color mFillColor;

  int mHp; //-1 - means unbreakable
  int mPoints;
};

#endif
