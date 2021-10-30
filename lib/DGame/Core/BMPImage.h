#ifndef BMPIMAGE_H_
#define BMPIMAGE_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif


#include <vector>
#include "Color.h"
#include <stdint.h>
#include <string>

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