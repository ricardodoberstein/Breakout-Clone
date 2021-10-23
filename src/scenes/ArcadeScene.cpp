#include "ArcadeScene.h"

ArcadeScene::ArcadeScene()
{
}

void ArcadeScene::Init()
{
  mTempSS.Load("ArcadeFont");

  ButtonAction action;
  action.key = GameController::ActionKey();
  action.action = [](uint32_t dt, InputState state)
  {
    if (GameController::IsPressed(state))
    {
      // Logic here...
    }
  };

  mGameController.AddInputActionForKey(action);

  MouseButtonAction mouseAction;
  mouseAction.mouseButton = GameController::LeftMouseButton();
  mouseAction.mouseInputAction = [](InputState state, const MousePosition &position)
  {
    if (GameController::IsPressed(state))
    {
      // Logic here...
    }
  };

  mGameController.AddMouseButtonAction(mouseAction);

  mGameController.SetMouseMovedAction([](const MousePosition &MousePosition) {
    // Logic here...
  });
}

void ArcadeScene::Update(uint32_t dt)
{
}

void ArcadeScene::Draw(Screen &screen)
{
  screen.Draw(mTempSS, "1", Vec2D::Zero);
}

const std::string &ArcadeScene::GetSceneName() const
{
  static std::string sceneName = "Arcade Scene";
  return sceneName;
}

std::unique_ptr<Scene> ArcadeScene::GetScene(eGame game)
{
  switch (game)
  {
  case TETRIS:
  {
  }
  break;

  case BREAK_OUT:
  {
  }
  break;

  case ASTEROIDS:
  {
  }
  break;

  case PACMAN:
  {
  }
  break;

  case NUM_GAMES:
  {
  }
  break;

  default:
  {
  }
  }

  return nullptr;
}