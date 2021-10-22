#ifndef GAMES_BREAKOUT_BLOCK_H_
#define GAMES_BREAKOUT_BLOCK_H_

#include "Excluder.h"
#include "../../graphics/Color.h"
#include "Ball.h"
#include "../../graphics/Screen.h"
#include "BoundaryEdge.h"

class Block : public Excluder
{
public:
  static const int UNBREAKABLE = -1;

  Block();
  void Init(const AARectangle &rect, int hp, const Color &outlineColor, const Color &fillColor);
  void Draw(Screen &screen);
  void Bounce(Ball &bounce, const BoundaryEdge &edge);

  void ReduceHP();
  inline int GetHP() const { return mHp; }
  inline bool IsDestroyed() const { return mHp == 0; }
  inline const Color &GetOutlineColor() const { return mOutlineColor; }
  inline const Color &GetFillColor() const { return mFillColor; }

private:
  Color mOutlineColor;
  Color mFillColor;

  int mHp; //-1 - means unbreakable
};

#endif
