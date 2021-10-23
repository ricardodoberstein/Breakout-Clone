#include "SpriteSheet.h"
#include "../utils/Utils.h"
#include "../app/App.h"
#include "../utils/FileCommandLoader.h"

SpriteSheet::SpriteSheet()
{
}

bool SpriteSheet::Load(const std::string &name)
{
  bool loadedImage = mBMPImage.Load(App::Singleton().GetBasePath() + std::string("assets/") + name + ".bmp");
  bool loadSpriteSection = LoadSpriteSections(App::Singleton().GetBasePath() + std::string("assets/") + name + ".txt");

  return loadedImage && loadSpriteSection;
}

Sprite SpriteSheet::GetSprite(const std::string &spriteName) const
{
  size_t length = mSection.size();

  for (size_t i = 0; i < length; ++i)
  {
    if (StringCompare(mSection[i].key, spriteName))
    {
      return mSection[i].sprite;
    }
  }

  return Sprite();
}

std::vector<std::string> SpriteSheet::SpriteNames() const
{
  std::vector<std::string> spriteNames;
  for (const auto &section : mSection)
  {
    spriteNames.push_back(section.key);
  }

  return spriteNames;
}

bool SpriteSheet::LoadSpriteSections(const std::string &path)
{
  FileCommandLoader fileLoader;

  Command spriteCommand;
  spriteCommand.command = "sprite";

  spriteCommand.parseFunction = [&](ParseFuncParams params)
  {
    BMPImageSection section;
    mSection.push_back(section);
  };

  fileLoader.AddCommand(spriteCommand);

  Command keyCommand;
  keyCommand.command = "key";

  keyCommand.parseFunction = [&](ParseFuncParams params)
  {
    mSection.back().key = FileCommandLoader::ReadString(params);
  };

  fileLoader.AddCommand(keyCommand);

  Command xPosCommand;
  xPosCommand.command = "xPos";

  xPosCommand.parseFunction = [&](ParseFuncParams params)
  {
    mSection.back().sprite.xPos = FileCommandLoader::ReadInt(params);
  };

  fileLoader.AddCommand(xPosCommand);

  Command yPosCommand;
  yPosCommand.command = "yPos";

  yPosCommand.parseFunction = [&](ParseFuncParams params)
  {
    mSection.back().sprite.yPos = FileCommandLoader::ReadInt(params);
  };

  fileLoader.AddCommand(yPosCommand);

  Command widthCommand;
  widthCommand.command = "width";

  widthCommand.parseFunction = [&](ParseFuncParams params)
  {
    mSection.back().sprite.width = FileCommandLoader::ReadInt(params);
  };

  fileLoader.AddCommand(widthCommand);

  Command heightCommand;
  heightCommand.command = "height";

  heightCommand.parseFunction = [&](ParseFuncParams params)
  {
    mSection.back().sprite.height = FileCommandLoader::ReadInt(params);
  };

  fileLoader.AddCommand(heightCommand);

  return fileLoader.LoadFile(path);
}
