#include "BitmapFont.h"

namespace DGame
{
  BitmapFont::BitmapFont()
  {
  }

  bool BitmapFont::Load(const std::string &name)
  {
    return mFontSheet.Load(name);
  }

  Size BitmapFont::GetSizeOf(const std::string &str)
  {
    Size textSize;
    size_t length = str.length();

    int i = 0;
    for (char c : str)
    {
      if (c == ' ')
      {
        textSize.width += GetFontSpacingBetweenWords();
        ++i;
        continue;
      }

      Sprite sprite = mFontSheet.GetSprite(std::string("") + c);
      textSize.height = textSize.height < sprite.height ? sprite.height : textSize.height;
      textSize.width += sprite.width;

      if (i + 1 < length)
      {
        textSize.width += GetFontSpaceingBetweenLetters();
      }

      ++i;
    }

    return textSize;
  }

  Vec2D BitmapFont::GetDrawPosition(const std::string &str, const AARectangle &box, BitmapFontXAligment xAlign, BitmapFontYAligment yAlign)
  {
    Size textSize = GetSizeOf(str);

    uint32_t x = 0;
    uint32_t y = 0;

    if (xAlign == BFXA_CENTER)
    {
      x = box.GetWidth() / 2 - textSize.width / 2;
    }
    else if (xAlign = BFXA_RIGHT)
    {
      x = box.GetWidth() - textSize.width;
    }

    x += box.GetTopLeftPoint().GetX();

    if (yAlign = BFYA_CENTER)
    {
      y = (box.GetHeight() / 2) - textSize.height / 2;
    }
    else if (yAlign = BFYA_BOTTOM)
    {
      y = box.GetHeight() - textSize.height;
    }

    y += box.GetTopLeftPoint().GetY();

    return Vec2D(x, y);
  }

}
