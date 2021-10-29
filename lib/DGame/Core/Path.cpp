#include "Path.h"

namespace DGame
{
  const std::string &Path::GetBasePath()
  {
    static std::string basePath = SDL_GetBasePath();

    return basePath;
  }
}