#ifndef GAMES_BREAKOUT_BREAKOUTGAMELEVEL_H_
#define GAMES_BREAKOUT_BREAKOUTGAMELEVEL_H_

#include "Block.h"
#include <vector>
#include <stdint.h>
#include "../../graphics/Screen.h"
#include "Ball.h"
#include "../../shapes/AARectangle.h"
#include "../../app/App.h"
#include "../../utils/FileCommandLoader.h"

class BreakoutGameLevel
{
public:
  BreakoutGameLevel();

  void Init(const AARectangle &boundary);
  void Load(const std::vector<Block> &blocks);
  void Update(uint32_t dt, Ball &ball);
  void Draw(Screen &screen);

  bool IsLevelComplete() const;
  static std::vector<BreakoutGameLevel> LoadLevelsFromFile(const std::string& filePath);

private:
	static const int BLOCK_WIDTH = 16;
	static const int BLOCK_HEIGHT = 8;
  void CreateDefaultLevel(const AARectangle &boundary);
  std::vector<Block> mBlocks;
};

#endif
