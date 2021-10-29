#ifndef PATH_H_
#define PATH_H_

#include <string>
#include <SDL2/SDL.h>

namespace DGame
{
  class Path
  {
  public:
    static const std::string &GetBasePath();
  };

}

#endif