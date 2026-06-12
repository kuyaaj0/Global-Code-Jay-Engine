#include "Engine.hpp"

#include "../Systems/WindowManager.hpp"
#include "../Renderer/Renderer.hpp"
#include "../Input/InputManager.hpp"
#include "../Audio/AudioManager.hpp"
#include "../Managers/AssetManager.hpp"
#include "../Scripting/ScriptManager.hpp"
#include "../Gameplay/GameplayState.hpp"

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

    gameplay = new GameplayState();

    running = true;

    return true;
}

void Engine::Run()
{
    while(running)
    {
        input->Update();

        gameplay->Update();

        scripts->ExecuteAll();

        renderer->Render();

        // Future:
        // window->Present();
    }
}

void Engine::Shutdown()
{
    delete gameplay;
    delete scripts;
    delete assets;
    delete audio;
    delete input;
    delete renderer;
    delete window;

    running = false;
}
