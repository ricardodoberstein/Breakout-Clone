#ifndef BMPIMAGE_H_
#define BMPIMAGE_H_

#include <vector>
#include "Color.h"
#include <stdint.h>
#include <string>
#include <SDL.h>

namespace DGame
{
  class BMPImage
  {
  public:
    BMPImage();
    bool Load(const std::string &path);

    inline const std::vector<Color> &GetPixels() const { return mPixels; }
    inline const uint32_t GetWidth() const { return mWdith; }
    inline const uint32_t GetHeight() const { return mHeight; }

  private:
    std::vector<Color> mPixels;
    uint32_t mWdith;
    uint32_t mHeight;
  };

}

#endif