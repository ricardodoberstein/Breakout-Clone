const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 288;

const int MAGNIFICATION = 3;

#include "App.h"
#include "BreakOut.h"
#include "BreakoutGameLevel.h"

int main()
{
  if (App::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION))
  {
    std::unique_ptr<BreakOut> breakoutGame = std::make_unique<BreakOut>();
    std::unique_ptr<GameScene> breakoutScene = std::make_unique<GameScene>(std::move(breakoutGame));
    App::Singleton().PushScene(std::move(breakoutScene));

    App::Singleton().Run();
  }

  return 0;
}
