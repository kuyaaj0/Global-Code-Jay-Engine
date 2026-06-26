#include "MainMenuState.hpp"
#include "../Renderer/Renderer.hpp"

#include <iostream>

MainMenuState::MainMenuState()
{
    currentSelection = 0;
}

bool MainMenuState::Initialize()
{
    std::cout << std::endl;

    std::cout << "========== MAIN MENU ==========" << std::endl;

    std::cout << "[0] Story Mode" << std::endl;
    std::cout << "[1] Freeplay" << std::endl;
    std::cout << "[2] Options" << std::endl;
    std::cout << "[3] Credits" << std::endl;

    std::cout << "===============================" << std::endl;

    return true;
}

void MainMenuState::Update(float deltaTime)
{
    // Keyboard / Touch input comes later.
}

void MainMenuState::Render(Renderer* renderer)
{
    // Future renderer.
}

void MainMenuState::Shutdown()
{
    std::cout << "[MainMenu] Shutdown." << std::endl;
}
