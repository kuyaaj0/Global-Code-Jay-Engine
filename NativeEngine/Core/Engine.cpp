#include "Engine.hpp"

#include "../Systems/WindowManager.hpp"
#include "../Renderer/Renderer.hpp"
#include "../States/InputManager.hpp"
#include "../Audio/AudioManager.hpp"
#include "../Manager/AssetManager.hpp"
#include "../Scripting/ScriptManager.hpp"
#include "../States/StateManager.hpp"
#include "../States/TitleState.hpp"

Engine::Engine()
{
    window = nullptr;
    renderer = nullptr;
    input = nullptr;
    audio = nullptr;
    assets = nullptr;
    scripts = nullptr;
    gameplay = nullptr;

    running = false;
}

bool Engine::Initialize()
{
    window = new WindowManager();

    renderer = new Renderer();

    input = new InputManager();

    audio = new AudioManager();

    assets = new AssetManager();

    scripts = new ScriptManager();

    stateManager = new StateManager();

    stateManager->ChangeState(new TitleState());

    running = true;

    return true;
}

void Engine::Run()
{
    while(running)
{
    float deltaTime = timer.GetDeltaTime();

    input->Update();

    stateManager->Update(deltaTime);

    scripts->ExecuteAll();

    stateManager->Render(renderer);

    window->Present();
}
}

void Engine::Shutdown()
{
    delete stateManager;
    delete scripts;
    delete assets;
    delete audio;
    delete input;
    delete renderer;
    delete window;

    running = false;
}
