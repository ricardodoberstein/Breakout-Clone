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
	Block* noptrBlockToBounceOffOf = nullptr;

	float largestMag = -1.0f;

	for(auto& block : mBlocks)
	{
		BoundaryEdge edge;

		if(!block.IsDestroyed() &&
			block.HasCollided(ball.GetBoundingRect(), edge))
		{
			collidedBlocks.push_back(block);

			float mag = block.GetCollisionOffset(ball.GetBoundingRect()).Magnitude();

			if(mag > largestMag)
			{
				edgeToBounceOffOf = edge;
				noptrBlockToBounceOffOf = &block;
			}
		}
	}

	if(noptrBlockToBounceOffOf != nullptr)
	{
		noptrBlockToBounceOffOf->Bounce(ball, edgeToBounceOffOf);
		noptrBlockToBounceOffOf->ReduceHP();
	}

	for(const auto & block : collidedBlocks)
	{
		BoundaryEdge edge;
		if(block.HasCollided(ball.GetBoundingRect(), edge))
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

	const int NUM_BLOCKS_ACROSS = ((int)boundary.GetWidth() - (2*(BLOCK_WIDTH))/ BLOCK_WIDTH);
	const int NUM_BLOCK_ROWS = 5;

	float startX = ((int)boundary.GetWidth() - (NUM_BLOCKS_ACROSS * (BLOCK_WIDTH+1)))/2;

	Color colors[NUM_BLOCK_ROWS];
	colors[0] = Color::Red();
	colors[1] = Color::Megenta();
	colors[2] = Color::Yellow();
	colors[3] = Color::Green();
	colors[4] = Color::Cyan();

	for(int r = 0; r < NUM_BLOCK_ROWS; ++r)
	{
		AARectangle blockRect = {Vec2D(startX, BLOCK_HEIGHT * (r+1)), BLOCK_WIDTH, BLOCK_HEIGHT};

		for(int c = 0; c < NUM_BLOCKS_ACROSS; ++c)
		{
			Block b;
			b.Init(blockRect, 1, Color::Black(), colors[r]);
			mBlocks.push_back(b);
			blockRect.MoveBy(Vec2D(BLOCK_WIDTH, 0));
		}
	}
}
