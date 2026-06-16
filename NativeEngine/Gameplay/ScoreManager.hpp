#pragma once

#include "JudgeResult.hpp"

class ScoreManager
{

public:

    ScoreManager();

    void AddJudge(
        JudgeResult result
    );

    int GetScore() const;

    int GetCombo() const;

    int GetMisses() const;

private:

    int score;

    int combo;

    int misses;

};
