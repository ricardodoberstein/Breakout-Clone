#ifndef GAMES_BREAKOUT_BOUNDARYEDGE_H_
#define GAMES_BREAKOUT_BOUNDARYEDGE_H_

#include "../../utils/Vec2D.h"
#include "../../shapes/Line2D.h"

enum EdgeType
{
  BOTTOM_EDGE = 0,
  TOP_EDGE,
  LEFT_EDGE,
  RIGHT_EDGE,
  NUM_EDGES
};

static const Vec2D UP_DIR = {0, -1};
static const Vec2D DOWN_DIR = {0, 1};
static const Vec2D LEFT_DIR = {-1, 0};
static const Vec2D RIGHT_DIR = {1, 0};

struct BoundaryEdge
{
  Vec2D normal;
  Line2D edge;
};

#endif