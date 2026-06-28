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

    if(inputCooldown < 0.15f)
        return;

    if(inputManager->IsUpPressed())
    {
        MoveUp();
        inputCooldown = 0.0f;
    }

    if(inputManager->IsDownPressed())
    {
        MoveDown();
        inputCooldown = 0.0f;
    }

    if(inputManager->IsConfirmPressed())
    {
        SelectOption();
        inputCooldown = 0.0f;
    }

    if(inputManager->IsBackPressed())
    {
        stateManager->ChangeState(
            new TitleState()
        );

        inputCooldown = 0.0f;
    }
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
    const int menuCount =
        sizeof(menuItems) / sizeof(menuItems[0]);

    selectedOption--;

    if(selectedOption < 0)
        selectedOption = menuCount - 1;
}

void MainMenuState::MoveDown()
{
    const int menuCount =
        sizeof(menuItems) / sizeof(menuItems[0]);

    selectedOption++;

    if(selectedOption >= menuCount)
        selectedOption = 0;
}

void MainMenuState::SelectOption()
{
    switch(selectedOption)
    {
        case 0:
            // Story Mode
            stateManager->ChangeState(
                new StoryMenuState()
            );
            break;

        case 1:
            // Freeplay
            stateManager->ChangeState(
                new FreeplayState()
            );
            break;

        case 2:
            // Options
            stateManager->ChangeState(
                new OptionsState()
            );
            break;

        case 3:
            // Credits
            stateManager->ChangeState(
                new CreditsState()
            );
            break;

        case 4:
            // Exit
            // We'll close the engine later.
            break;
    }
}

void MainMenuState::Shutdown()
{
    std::cout << "[MainMenu] Shutdown." << std::endl;
}
