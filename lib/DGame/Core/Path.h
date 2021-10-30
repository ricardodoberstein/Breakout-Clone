#ifndef PATH_H_
#define PATH_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif


#include <string>

namespace DGame
{
  class Path
  {
  public:
    static const std::string &GetBasePath();
  };

}

#endif