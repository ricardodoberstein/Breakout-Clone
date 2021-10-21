#include "App.h"

App &App::Singleton()
{
  static App theApp;
  return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
  mnoptrWindow = mScreen.Init(width, height, mag);

  std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();
  
  PushScene(std::move(arcadeScene));

  //temp
  {
    std::unique_ptr<BreakOut> breakoutGame = std::make_unique<BreakOut>();
    std::unique_ptr<GameScene> breakoutScene = std::make_unique<GameScene>(std::move(breakoutGame));

    PushScene(std::move(breakoutScene));
  }

  return mnoptrWindow != nullptr;
}

void App::Run()
{
  bool running = true;

  uint32_t lastTick = SDL_GetTicks();
  uint32_t currentTick = lastTick;

  uint32_t dt = 10;
  uint32_t accumulator = 0;

  mInputController.Init([&running](uint32_t dt, InputState state) {
    running = false;
  });

  while (running)
  {
    currentTick = SDL_GetTicks();
    uint32_t frameTime = currentTick - lastTick;

    if (frameTime > 300)
    {
      frameTime = 300;
    }

    lastTick = currentTick;

    accumulator += frameTime;

    //Input
    mInputController.Update(dt);

    Scene *scene = App::TopScene();

    if (scene)
    {
      while (accumulator >= dt)
      {
        //update current scene by dt
        scene->Update(dt);
        accumulator -= dt;
      }

      //Render
      scene->Draw(mScreen);
      mScreen.SwapScreen();
    }
  }
}

void App::PushScene(std::unique_ptr<Scene> scene)
{
  if (scene)
  {
    scene->Init();
    mInputController.SetGameController(scene->GetGameController());
    mSceneStack.emplace_back(std::move(scene));
    SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
  }
}

void App::PopScene()
{
  if (mSceneStack.size() > 1)
  {
    mSceneStack.pop_back();
  }

  if (TopScene())
  {
    mInputController.SetGameController(TopScene()->GetGameController());
    SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
  }
}

Scene *App::TopScene()
{
  if (mSceneStack.empty())
  {
    return nullptr;
  }

  return mSceneStack.back().get();
}