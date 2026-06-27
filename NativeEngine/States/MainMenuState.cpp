#include "MainMenuState.hpp"

#include "../Renderer/Renderer.hpp"

#include <iostream>

MainMenuState::MainMenuState()
{
    selectedOption = 0;

    inputCooldown = 0.0f;
}

bool MainMenuState::Initialize()
{
    std::cout << "[MainMenu] Initialize." << std::endl;

    std::cout << "------------------------" << std::endl;

    for(int i = 0; i < 5; i++)
    {
        if(i == selectedOption)
            std::cout << "> ";
        else
            std::cout << "  ";

        std::cout << menuItems[i] << std::endl;
    }

    return true;
}

void MainMenuState::Update(float deltaTime)
{
    inputCooldown += deltaTime;

    // Touch input
    // Keyboard
    // Controller

    // will be connected later
}

void MainMenuState::Render(Renderer* renderer)
{
    // Draw background

    // Draw logo

    // Draw menu

    // Draw selector
}

void MainMenuState::DrawMenu()
{
    std::cout << "\n";

    std::cout << "===== MAIN MENU =====\n";

    for(int i = 0; i < MENU_COUNT; i++)
    {
        if(i == selectedOption)
            std::cout << "> ";
        else
            std::cout << "  ";

        std::cout << menuItems[i] << std::endl;
    }

    std::cout << std::endl;
}

void MainMenuState::MoveUp()
{
    selectedOption--;

    if(selectedOption < 0)
        selectedOption = MENU_COUNT - 1;

    DrawMenu();
}

void MainMenuState::MoveDown()
{
    selectedOption++;

    if(selectedOption >= MENU_COUNT)
        selectedOption = 0;

    DrawMenu();
}

void MainMenuState::SelectOption()
{
    switch(selectedOption)
    {
        case 0:
            std::cout << "[MainMenu] Story Mode Selected." << std::endl;
            break;

        case 1:
            std::cout << "[MainMenu] Freeplay Selected." << std::endl;
            break;

        case 2:
            std::cout << "[MainMenu] Options Selected." << std::endl;
            break;

        case 3:
            std::cout << "[MainMenu] Credits Selected." << std::endl;
            break;

        case 4:
            std::cout << "[MainMenu] Exit Selected." << std::endl;
            break;
    }
}

void MainMenuState::Shutdown()
{
    std::cout << "[MainMenu] Shutdown." << std::endl;
}
