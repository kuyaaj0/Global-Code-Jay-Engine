#include "StoryMenuState.hpp"

#include "../Renderer/Renderer.hpp"
#include "GameplayState.hpp"
#include "MainMenuState.hpp"

#include <iostream>

StoryMenuState::StoryMenuState()
{
    showingJayStory = true;

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
        SelectWeek();
        inputCooldown = 0.0f;
    }

    if(inputManager->IsBackPressed())
    {
        GoBack();
        inputCooldown = 0.0f;
    }

    // Future:
    // Left / Right switches between Jay Story and Original FNF
    /*
    if(inputManager->IsLeftPressed())
    {
        ToggleStorySource();
        inputCooldown = 0.0f;
    }

    if(inputManager->IsRightPressed())
    {
        ToggleStorySource();
        inputCooldown = 0.0f;
    }
    */
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

    if(showingJayStory)
        std::cout << "▶ Jay Engine\n";
    else
        std::cout << "  Jay Engine\n";

    if(!showingJayStory)
        std::cout << "▶ Original FNF\n";
    else
        std::cout << "  Original FNF\n";

    std::cout << "\n------------------------------\n";

    const char** currentStory =
        showingJayStory ? jayStory : fnfWeeks;

    int storyCount =
        GetCurrentWeekCount();

    for(int i = 0; i < storyCount; i++)
    {
        if(i == selectedWeek)
            std::cout << "> ";
        else
            std::cout << "  ";

        std::cout << currentStory[i] << std::endl;
    }

    std::cout << std::endl;
}

int StoryMenuState::GetCurrentWeekCount() const
{
    return showingJayStory
        ? JAY_CHAPTER_COUNT
        : FNF_WEEK_COUNT;
}

void StoryMenuState::MoveUp()
{
    selectedWeek--;

    int maxItems =
        GetCurrentWeekCount();

    if(selectedWeek < 0)
        selectedWeek = maxItems - 1;

    DrawMenu();
}

void StoryMenuState::MoveDown()
{
    selectedWeek++;

    int maxItems =
        GetCurrentWeekCount();

    if(selectedWeek >= maxItems)
        selectedWeek = 0;

    DrawMenu();
}

void StoryMenuState::ToggleStorySource()
{
    showingJayStory = !showingJayStory;

    selectedWeek = 0;

    DrawMenu();
}

void StoryMenuState::SelectWeek()
{
    std::string weekID;

    if(showingJayStory)
    {
        switch(selectedWeek)
        {
            case 0: weekID = "chapter1"; break;
            case 1: weekID = "chapter2"; break;
            case 2: weekID = "chapter3"; break;

            default:
                weekID = "chapter1";
                break;
        }
    }
    else
    {
        switch(selectedWeek)
        {
            case 0: weekID = "week1"; break;
            case 1: weekID = "week2"; break;
            case 2: weekID = "week3"; break;
            case 3: weekID = "week4"; break;
            case 4: weekID = "week5"; break;
            case 5: weekID = "week6"; break;
            case 6: weekID = "week7"; break;

            default:
                weekID = "week1";
                break;
        }
    }

    WeekData week =
        weekLoader.LoadWeek(weekID);

    std::cout
        << "[StoryMenu] Loaded "
        << week.weekName
        << std::endl;

    // GameplayState will receive WeekData later

    stateManager->ChangeState(
    new GameplayState(
        week
    )
);
}

void StoryMenuState::GoBack()
{
    stateManager->ChangeState(
        new MainMenuState()
    );
}
