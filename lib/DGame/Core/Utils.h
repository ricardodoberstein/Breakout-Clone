#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <algorithm>
#include <cctype>

namespace DGame
{
  static const float EPSILON = 0.0001f;

  const float PI = 3.14159;
  const float TWO_PI = 2.0f * PI;

  bool IsEqual(float x, float y);

  bool IsGreaterThanOrEqual(float x, float y);

  bool IsLessThanOrEqual(float x, float y);

  float MillisecondsToSeconds(unsigned int milliseconds);

  unsigned int GetIndex(unsigned int width, unsigned int r, unsigned int c);

  bool StringCompare(const std::string &a, const std::string &b);

  float Clamp(float val, float min, float max);

  struct Size
  {
    unsigned int width = 0, height = 0;
  };
}

#endif