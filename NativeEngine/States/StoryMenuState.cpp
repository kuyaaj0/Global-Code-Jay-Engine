#include "StoryMenuState.hpp"

#include "../Renderer/Renderer.hpp"
#include "GameplayState.hpp"
#include "MainMenuState.hpp"

#include <iostream>

StoryMenuState::StoryMenuState()
{
    useJayStory = true;

    selectedWeek = 0;

    inputCooldown = 0.0f;
}

bool StoryMenuState::Initialize()
{
    std::cout << "[StoryMenu] Initialize." << std::endl;

    DrawMenu();

    return true;
}

void StoryMenuState::Update(float deltaTime)
{
    inputCooldown += deltaTime;

    // InputManager will be connected later.
}

void StoryMenuState::Render(Renderer* renderer)
{
    // Renderer integration later.
}

void StoryMenuState::Shutdown()
{
    std::cout << "[StoryMenu] Shutdown." << std::endl;
}

void StoryMenuState::DrawMenu()
{
    std::cout << "\n";

    std::cout << "==============================" << std::endl;
    std::cout << "         STORY MODE" << std::endl;
    std::cout << "==============================" << std::endl;

    std::cout << "\nStory Source\n";

    if(useJayStory)
        std::cout << "▶ Jay Engine\n";
    else
        std::cout << "  Jay Engine\n";

    if(!useJayStory)
        std::cout << "▶ Original FNF\n";
    else
        std::cout << "  Original FNF\n";

    std::cout << "\n------------------------------\n";

    if(useJayStory)
    {
        for(int i = 0; i < JAY_CHAPTER_COUNT; i++)
        {
            if(i == selectedWeek)
                std::cout << "> ";
            else
                std::cout << "  ";

            std::cout << jayStory[i] << std::endl;
        }
    }
    else
    {
        for(int i = 0; i < FNF_WEEK_COUNT; i++)
        {
            if(i == selectedWeek)
                std::cout << "> ";
            else
                std::cout << "  ";

            std::cout << fnfWeeks[i] << std::endl;
        }
    }

    std::cout << std::endl;
}

void StoryMenuState::MoveUp()
{
    selectedWeek--;

    int maxItems =
        useJayStory ? JAY_CHAPTER_COUNT : FNF_WEEK_COUNT;

    if(selectedWeek < 0)
        selectedWeek = maxItems - 1;

    DrawMenu();
}

void StoryMenuState::MoveDown()
{
    int maxItems =
        useJayStory ? JAY_CHAPTER_COUNT : FNF_WEEK_COUNT;

    selectedWeek++;

    if(selectedWeek >= maxItems)
        selectedWeek = 0;

    DrawMenu();
}

void StoryMenuState::ToggleStorySource()
{
    useJayStory = !useJayStory;

    selectedWeek = 0;

    DrawMenu();
}

void StoryMenuState::SelectWeek()
{
    if(useJayStory)
    {
        std::cout << "[StoryMenu] Loading "
                  << jayStory[selectedWeek]
                  << std::endl;
    }
    else
    {
        std::cout << "[StoryMenu] Loading "
                  << fnfWeeks[selectedWeek]
                  << std::endl;
    }

    stateManager->ChangeState(
    new GameplayState()
);
}

void StoryMenuState::GoBack()
{
    stateManager->ChangeState(
        new MainMenuState()
    );
}
