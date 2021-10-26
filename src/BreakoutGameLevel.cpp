#include "BreakoutGameLevel.h"

BreakoutGameLevel::BreakoutGameLevel()
{
}

void BreakoutGameLevel::Init(const AARectangle &boundary)
{
	CreateDefaultLevel(boundary);
}

void BreakoutGameLevel::Load(const std::vector<Block> &blocks)
{
	mBlocks.clear();
	mBlocks = blocks;
}

void BreakoutGameLevel::Update(uint32_t dt, Ball &ball)
{
	std::vector<Block> collidedBlocks;

	BoundaryEdge edgeToBounceOffOf;
	Block *noptrBlockToBounceOffOf = nullptr;

	float largestMag = -1.0f;

	for (auto &block : mBlocks)
	{
		BoundaryEdge edge;

		if (!block.IsDestroyed() &&
				block.HasCollided(ball.GetBoundingRect(), edge))
		{
			collidedBlocks.push_back(block);

			float mag = block.GetCollisionOffset(ball.GetBoundingRect()).Magnitude();

			if (mag > largestMag)
			{
				edgeToBounceOffOf = edge;
				noptrBlockToBounceOffOf = &block;
			}
		}
	}

	if (noptrBlockToBounceOffOf != nullptr)
	{
		noptrBlockToBounceOffOf->Bounce(ball, edgeToBounceOffOf);
		noptrBlockToBounceOffOf->ReduceHP();
	}

	for (const auto &block : collidedBlocks)
	{
		BoundaryEdge edge;
		if (block.HasCollided(ball.GetBoundingRect(), edge))
		{
			Vec2D p;
			ball.MakeFlushWithEdge(edge, p, true);
		}
	}
}

void BreakoutGameLevel::Draw(Screen &screen)
{
	for (auto &block : mBlocks)
	{
		if (!block.IsDestroyed())
		{
			block.Draw(screen);
		}
	}
}

void BreakoutGameLevel::CreateDefaultLevel(const AARectangle &boundary)
{
	mBlocks.clear();

	const int NUM_BLOCKS_ACROSS = ((int)boundary.GetWidth() - (2 * (BLOCK_WIDTH)) / BLOCK_WIDTH);
	const int NUM_BLOCK_ROWS = 5;

	float startX = ((int)boundary.GetWidth() - (NUM_BLOCKS_ACROSS * (BLOCK_WIDTH + 1))) / 2;

	Color colors[NUM_BLOCK_ROWS];
	colors[0] = Color::Red();
	colors[1] = Color::Megenta();
	colors[2] = Color::Yellow();
	colors[3] = Color::Green();
	colors[4] = Color::Cyan();

	for (int r = 0; r < NUM_BLOCK_ROWS; ++r)
	{
		AARectangle blockRect = {Vec2D(startX, BLOCK_HEIGHT * (r + 1)), BLOCK_WIDTH, BLOCK_HEIGHT};

		for (int c = 0; c < NUM_BLOCKS_ACROSS; ++c)
		{
			Block b;
			b.Init(blockRect, 1, Color::Black(), colors[r]);
			mBlocks.push_back(b);
			blockRect.MoveBy(Vec2D(BLOCK_WIDTH, 0));
		}
	}
}

struct LayoutBlock
{
	char symbol = '-';
	int hp = 0;
	Color color = Color::Black();
};

LayoutBlock FindLayoutBlockForSymbol(const std::vector<LayoutBlock> &blocks, char symbol)
{
	for (size_t i = 0; i < blocks.size(); ++i)
	{
		if (blocks[i].symbol == symbol)
		{
			return blocks[i];
		}
	}

	return LayoutBlock();
}

std::vector<BreakoutGameLevel> BreakoutGameLevel::LoadLevelsFromFile(const std::string &filePath)
{
	std::vector<BreakoutGameLevel> levels;

	std::vector<LayoutBlock> layoutBlocks;

	std::vector<Block> levelBlocks;

	int width = 0;
	int height = 0;

	FileCommandLoader fileLoader;

	Command levelCommand;
	levelCommand.command = "level";
	levelCommand.parseFunction = [&](ParseFuncParams params)
	{
		if (levels.size() > 0)
		{
			levels.back().Load(levelBlocks);
		}
		layoutBlocks.clear();
		levelBlocks.clear();
		width = 0;
		height = 0;

		BreakoutGameLevel level;
		level.Init(AARectangle(Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height()));

		levels.push_back(level);
	};

	fileLoader.AddCommand(levelCommand);

	Command blockCommand;
	blockCommand.command = "block";
	blockCommand.parseFunction = [&](ParseFuncParams params)
	{
		LayoutBlock lb;

		layoutBlocks.push_back(lb);
	};

	fileLoader.AddCommand(blockCommand);

	Command symbolCommand;
	symbolCommand.command = "symbol";
	symbolCommand.parseFunction = [&](ParseFuncParams params)
	{
		layoutBlocks.back().symbol = FileCommandLoader::ReadChar(params);
	};

	fileLoader.AddCommand(symbolCommand);

	Command fillColorCommand;
	fillColorCommand.command = "fillcolor";
	fillColorCommand.parseFunction = [&](ParseFuncParams params)
	{
		layoutBlocks.back().color = FileCommandLoader::ReadColor(params);
	};

	fileLoader.AddCommand(fillColorCommand);

	Command hpCommand;
	hpCommand.command = "hp";
	hpCommand.parseFunction = [&](ParseFuncParams params)
	{
		layoutBlocks.back().hp = FileCommandLoader::ReadInt(params);
	};

	fileLoader.AddCommand(hpCommand);

	Command widthCommand;
	widthCommand.command = "width";
	widthCommand.parseFunction = [&](ParseFuncParams params)
	{
		width = FileCommandLoader::ReadInt(params);
	};

	fileLoader.AddCommand(widthCommand);

	Command heightCommand;
	heightCommand.command = "height";
	heightCommand.parseFunction = [&](ParseFuncParams params)
	{
		width = FileCommandLoader::ReadInt(params);
	};

	fileLoader.AddCommand(heightCommand);

	Command layoutCommand;
	layoutCommand.commandType = COMMAND_MULTI_LINE;
	layoutCommand.command = "layout";
	layoutCommand.parseFunction = [&](ParseFuncParams params)
	{
		float startingX = 0;
		AARectangle blockRect(Vec2D(startingX, (params.lineNum + 1) * BLOCK_HEIGHT), BLOCK_WIDTH, BLOCK_HEIGHT);

		for (int c = 0; c < params.line.length(); ++c)
		{
			if (params.line[c] != '-')
			{
				LayoutBlock layoutBlock = FindLayoutBlockForSymbol(layoutBlocks, params.line[c]);

				Block b;
				b.Init(blockRect, layoutBlock.hp, Color::Black(), layoutBlock.color);
				levelBlocks.push_back(b);
			}
			blockRect.MoveBy(Vec2D(BLOCK_WIDTH, 0));
		}
	};

	fileLoader.AddCommand(layoutCommand);

	fileLoader.LoadFile(filePath);

	if (levels.size() > 0)
	{
		levels.back().Load(levelBlocks);
	}

	return levels;
}

bool BreakoutGameLevel::IsLevelComplete() const
{
	for(size_t i = 0; i < mBlocks.size(); ++i)
	{
		if (!mBlocks[i].IsDestroyed() && mBlocks[i].GetHP() != Block::UNBREAKABLE)
		{
			return false;
		}
	}

	return true;
}
