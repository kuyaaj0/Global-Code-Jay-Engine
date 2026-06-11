#include "GameplayState.hpp"

GameplayState::GameplayState()
{

}

void GameplayState::Load()
{
    playField.Reset();

    noteManager.Clear();

    modifierManager.Reset();
}

void GameplayState::Update(
float dt)
{
    input.Update();

    events.Update(
        audio.GetPosition()
    );

    noteManager.Update(dt);
}

void GameplayState::Render()
{
    renderer.BeginFrame();

    noteManager.Render(renderer);

    renderer.EndFrame();
}

void GameplayState::Reset()
{
    noteManager.Clear();

    modifierManager.Reset();

    playField.Reset();
}
