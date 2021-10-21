#ifndef UTILS_FILECOMMANDLOADER_H_
#define UTILS_FILECOMMANDLOADER_H_

#include <functional>
#include <vector>
#include <string>
#include "../graphics/Color.h"
#include "Vec2D.h"
#include <stdint.h>
#include <fstream>
#include <iostream>

enum CommandType
{
  COMMAND_ONE_LINE = 0,
  COMMAND_MULTI_LINE
};

struct ParseFuncParams
{
  std::string line;
  size_t dilimitPos;
  uint32_t lineNum;
};

using ParseFunc = std::function<void(const ParseFuncParams &params)>;

struct Command
{
  CommandType commandType = COMMAND_ONE_LINE;
  std::string command = "";
  ParseFunc parseFunction = nullptr;
};

class FileCommandLoader
{
public:
  void AddCommand(const Command &command);
  bool LoadFile(const std::string &filePath);

  static Color ReadColor(const ParseFuncParams &params);
  static Vec2D ReadSize(const ParseFuncParams &params);
  static int ReadInt(const ParseFuncParams &params);
  static std::string ReadString(const ParseFuncParams &params);
  static char ReadChar(const ParseFuncParams &params);

private:
  std::vector<Command> mCommands;
};

#endif
