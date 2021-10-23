#ifndef GRAPHICS_SCREEN_H
#define GRAPHICS_SCREEN_H

#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"
#include "../utils/Vec2D.h"
#include "SDL2/SDL.h"
#include <cmath>
#include "../shapes/Line2D.h"
#include "../shapes/Triangle.h"
#include "../shapes/AARectangle.h"
#include "../shapes/Circle.h"
#include "../utils/Utils.h"
#include <vector>
#include <algorithm>
#include "../graphics/SpriteSheet.h"
#include "BitmapFont.h"

class BMPImage;

struct SDL_Window;
struct SDL_Surface;

class Screen
{
public:
  Screen();
  ~Screen();

  SDL_Window *Init(uint32_t w, uint32_t h, uint32_t mag);
  void SwapScreen();

  inline void SetClearColor(const Color &clearColor) { mClearColor = clearColor; }
  inline uint32_t Width() const { return mWidth; }
  inline uint32_t Height() const { return mHeight; }

  void Draw(int x, int y, const Color &color);
  void Draw(const Vec2D &point, const Color &color);
  void Draw(const Line2D &line, const Color &color);
  void Draw(const Triangle &triangle, const Color &color, bool fill = false, const Color &fillColor = Color::White().GetPixelColor());
  void Draw(const AARectangle &rect, const Color &color, bool fill = false, const Color &fillColor = Color::White().GetPixelColor());
  void Draw(const Circle &circle, const Color &color, bool fill = false, const Color &fillColor = Color::White().GetPixelColor());
  void Draw(const BMPImage &image, const Sprite &sprite, const Vec2D &pos);
  void Draw(const SpriteSheet &ss, const std::string &spriteName, const Vec2D &pos);
  void Draw(const BitmapFont& font, const std::string& textLine, const Vec2D& pos);

private:
  Screen(const Screen &screen);
  Screen &operator=(const Screen &screen);

  void ClearScreen();
  void FillPoly(const std::vector<Vec2D> &points, const Color &color);

  uint32_t mWidth;
  uint32_t mHeight;

  Color mClearColor;
  ScreenBuffer mBackBuffer;

  SDL_Window *noptrWindow;
  SDL_Surface *noptrSurface;
};

#endif