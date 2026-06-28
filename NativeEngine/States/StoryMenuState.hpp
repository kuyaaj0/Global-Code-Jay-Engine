#pragma once

#include "State.hpp"
#include "../Loader/WeekLoader.hpp"

class Renderer;

class StoryMenuState : public State
{
public:

    StoryMenuState();

    bool Initialize() override;

    void Update(float deltaTime) override;

    void Render(Renderer* renderer) override;

    void Shutdown() override;

private:

    WeekLoader weekLoader;

    void DrawMenu();

    void MoveUp();

    void MoveDown();

    void ToggleStorySource();

    void SelectWeek();

    void GoBack();

    bool showingJayStory;

    int selectedWeek;

    float inputCooldown;

    static constexpr int JAY_CHAPTER_COUNT = 3;

    static constexpr int FNF_WEEK_COUNT = 7;

    const char* jayStory[JAY_CHAPTER_COUNT]
    {
        "Chapter 1",
        "Chapter 2",
        "Chapter 3"
    };

    const char* fnfWeeks[FNF_WEEK_COUNT]
    {
        "Week 1",
        "Week 2",
        "Week 3",
        "Week 4",
        "Week 5",
        "Week 6",
        "Week 7"
    };
};
