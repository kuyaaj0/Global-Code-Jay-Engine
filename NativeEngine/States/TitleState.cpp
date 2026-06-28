#include "TitleState.hpp"
#include "../Renderer/Renderer.hpp"

#include <iostream>

TitleState::TitleState()
{
    timer = 0.0f;

    logoFinished = false;

    waitingForInput = false;

    blinkVisible = true;

    blinkTimer = 0.0f;
    
    //inputManager = nullptr;
}

bool TitleState::Initialize()
{
    std::cout << "==================================" << std::endl;
    std::cout << "        GLOBAL CODE JAY ENGINE" << std::endl;
    std::cout << "==================================" << std::endl;

    std::cout << "[TitleState] Initializing..." << std::endl;

    //inputManager = new InputManager();

    return true;
}

void TitleState::Update(float deltaTime)
{
    timer += deltaTime;

if(timer >= 3.0f && !logoFinished)
{
    logoFinished = true;

    waitingForInput = true;

    std::cout << "[TitleState] Intro Finished." << std::endl;
}

if(waitingForInput)
{
    blinkTimer += deltaTime;

    if(blinkTimer >= 0.5f)
    {
        blinkVisible = !blinkVisible;
        blinkTimer = 0.0f;
    }

    if(waitingForInput)
{
    inputManager->Update();

    if(inputManager->IsConfirmPressed())
    {
        stateManager->ChangeState(
            new MainMenuState()
        );
    }
}
}
}

void TitleState::Render(Renderer* renderer)
{
    // Renderer will be connected later.
}

void TitleState::Shutdown()
{
    std::cout << "[TitleState] Shutdown." << std::endl;
    //delete inputManager;
}
