#include "TitleState.hpp"

#include <iostream>

TitleState::TitleState()
{
    timer = 0.0f;
    logoFinished = false;
}

bool TitleState::Initialize()
{
    std::cout << "==================================" << std::endl;
    std::cout << "        GLOBAL CODE JAY ENGINE" << std::endl;
    std::cout << "==================================" << std::endl;

    std::cout << "[TitleState] Initializing..." << std::endl;

    return true;
}

void TitleState::Update(float deltaTime)
{
    timer += deltaTime;

    if(timer >= 3.0f && !logoFinished)
    {
        logoFinished = true;

        std::cout << "[TitleState] Intro Finished." << std::endl;

        // Later:
        // ChangeState(new MainMenuState());
    }
}

void TitleState::Render(Renderer* renderer)
{
    // Renderer will be connected later.
}

void TitleState::Shutdown()
{
    std::cout << "[TitleState] Shutdown." << std::endl;
}
