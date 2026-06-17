#pragma once

#include <string>

class HUD
{
public:

    float health;

    int score;

    int combo;

    int misses;

    float accuracy;

    std::string judgmentText;

    float judgmentTimer;

    void ShowJudgment(
    const std::string& text
);

    void Update();

    void Render();
};
