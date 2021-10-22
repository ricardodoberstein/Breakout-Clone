#ifndef GAMES_BREAKOUT_BREAKOUTGAMELEVEL_H_
#define GAMES_BREAKOUT_BREAKOUTGAMELEVEL_H_

#include <vector>
#include "../../graphics/Screen.h"
#include "Ball.h"
#include "../../shapes/AARectangle.h"
#include "Block.h"
#include <stdint.h>
#include <iostream>

class BreakoutGameLevel
{
public:
  BreakoutGameLevel();

  void Init(const AARectangle &boundary);
  void Load(const std::vector<Block> &blocks);
  void Update(uint32_t dt, Ball &ball);
  void Draw(Screen &screen);

private:
	static const int BLOCK_WIDTH = 16;
	static const int BLOCK_HEIGHT = 8;
  void CreateDefaultLevel(const AARectangle &boundary);
  std::vector<Block> mBlocks;
};

#endif
