#ifndef BITMAPFONT_H_
#define BITMAPFONT_H_

#include "SpriteSheet.h"
#include <stdint.h>
#include "AARectangle.h"
#include "Vec2D.h"
#include "Utils.h"

enum BitmapFontXAligment
{
  BFXA_LEFT = 0,
  BFXA_CENTER,
  BFXA_RIGHT
};

enum BitmapFontYAligment
{
  BFYA_TOP = 0,
  BFYA_CENTER,
  BFYA_BOTTOM
};

class BitmapFont
{
public:
  BitmapFont();
  bool Load(const std::string &name);
  Size GetSizeOf(const std::string &str);
  Vec2D GetDrawPosition(const std::string& str, const AARectangle& box, BitmapFontXAligment xAlign = BFXA_LEFT, BitmapFontYAligment yAlign = BFYA_TOP);

  inline const SpriteSheet& GetSpriteSheet() const { return mFontSheet; }
  inline const uint32_t GetFontSpaceingBetweenLetters() const { return 2; }
  inline const uint32_t GetFontSpacingBetweenWords() const { return 5; }

private:
  SpriteSheet mFontSheet;
};

#endif
