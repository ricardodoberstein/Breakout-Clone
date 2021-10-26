#include "Path.h"

const std::string &Path::GetBasePath()
{
  static std::string basePath = SDL_GetBasePath();

  return basePath;
}