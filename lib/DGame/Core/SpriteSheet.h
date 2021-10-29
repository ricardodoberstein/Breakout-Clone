#ifndef SPRITESHEET_H_
#define SPRITESHEET_H_

#include "BMPImage.h"
#include <string>
#include <vector>
#include <stdint.h>

struct Sprite
{
  uint32_t xPos = 0;
  uint32_t yPos = 0;
  uint32_t width = 0;
  uint32_t height = 0;
};

struct BMPImageSection
{
  std::string key = "";
  Sprite sprite;
};

class SpriteSheet
{
public:
  SpriteSheet();
  bool Load(const std::string &name);
  Sprite GetSprite(const std::string &spriteName) const;
  std::vector<std::string> SpriteNames() const;

  inline const BMPImage &GetBMPImage() const { return mBMPImage; }
  inline uint32_t GetWidth() const { return mBMPImage.GetWidth(); }
  inline uint32_t GetHeight() const { return mBMPImage.GetHeight(); }

private:
  bool LoadSpriteSections(const std::string &path);
  BMPImage mBMPImage;
  std::vector<BMPImageSection> mSection;
};

#endif