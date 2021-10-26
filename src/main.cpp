const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;

const int MAGNIFICATION = 3;

#include "App.h"

int main()
{
  if(App::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION));
  {
    App::Singleton().Run();
  }
  
  return 0;
}
