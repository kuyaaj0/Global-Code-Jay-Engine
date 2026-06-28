#include "MainMenuState.hpp"

#include "../Renderer/Renderer.hpp"
#include "StoryMenuState.hpp"

#include <iostream>

MainMenuState::MainMenuState()
{
    selectedOption = 0;

    inputCooldown = 0.0f;

    acceptingInput = false;
}

bool MainMenuState::Initialize()
{
    std::cout << "[MainMenu] Initialized." << std::endl;

    selectedOption = 0;

    inputCooldown = 0.0f;

    acceptingInput = true;

    return true;
}

void MainMenuState::Update(float deltaTime)
{
    if(!acceptingInput)
        return;

    inputCooldown += deltaTime;

    // Later:
    // InputManager
    //
    // if(UpPressed)
    //     MoveUp();
    //
    // if(DownPressed)
    //     MoveDown();
    //
    // if(ConfirmPressed)
    //     SelectOption();
}

void MainMenuState::Render(Renderer* renderer)
{
    DrawMenu();
}

void MainMenuState::Shutdown()
{
    std::cout << "[MainMenu] Shutdown." << std::endl;
}

void MainMenuState::DrawMenu()
{
    std::cout << "\n========== MAIN MENU ==========\n";

    for(int i = 0; i < 5; i++)
    {
        if(i == selectedOption)
            std::cout << "> ";
        else
            std::cout << "  ";

        std::cout << menuItems[i] << std::endl;
    }

    std::cout << "===============================\n";
}

void MainMenuState::MoveUp()
{
    if(selectedOption > 0)
        selectedOption--;
}

void MainMenuState::MoveDown()
{
    if(selectedOption < 4)
        selectedOption++;
}

void MainMenuState::SelectOption()
{
    switch(selectedOption)
    {
        case 0:
            std::cout << "Story Mode Selected" << std::endl;

            stateManager->ChangeState(
                new StoryMenuState()
            );
            break;

        case 1:
            std::cout << "Freeplay Selected" << std::endl;
            break;

        case 2:
            std::cout << "Options Selected" << std::endl;
            break;

        case 3:
            std::cout << "Credits Selected" << std::endl;
            break;

        case 4:
            std::cout << "Exit Selected" << std::endl;

            // Later:
            // Engine::Shutdown();
            break;
    }
}
}

void MainMenuState::Shutdown()
{
    std::cout << "[MainMenu] Shutdown." << std::endl;
}
