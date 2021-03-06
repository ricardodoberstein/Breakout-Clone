#ifndef BREAKOUTGAMELEVEL_H_
#define BREAKOUTGAMELEVEL_H_

#include "Block.h"
#include <vector>
#include <stdint.h>
#include "Ball.h"
#include <functional>
#include "DGame/DGame.h"

using namespace DGame;

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
  
  std::function<void (const Block& block)> onBlockDestroyed;

private:
	static const int BLOCK_WIDTH = 16;
	static const int BLOCK_HEIGHT = 8;
  void CreateDefaultLevel(const AARectangle &boundary);
  std::vector<Block> mBlocks;
};

#endif
