#include "ArcadeScene.h"

ArcadeScene::ArcadeScene()
{
}

void ArcadeScene::Init()
{
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
  Line2D line = {Vec2D(0, 0), Vec2D(screen.Width(), screen.Height())};
  Triangle triangle = {Vec2D(60, 10), Vec2D(10, 110), Vec2D(110, 110)};
  AARectangle rect = {Vec2D(screen.Width() / 2 - 25, screen.Height() / 2 - 25), 50, 50};
  Circle circle = {Vec2D(screen.Width() / 2 + 50, screen.Height() / 2 + 50), 50};
  screen.Draw(triangle, Color::Red(), true, Color::Red());
  screen.Draw(rect, Color::Blue(), true, Color::Blue());
  screen.Draw(circle, Color(0, 255, 0, 150), true, Color(0, 255, 0, 150));
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