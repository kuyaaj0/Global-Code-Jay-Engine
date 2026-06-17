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

    float GetAccuracy() const;

private:

    int score;
    int combo;
    int misses;

    int marvelousCount;
    int sickCount;
    int goodCount;
    int badCount;
    int missCount;

};
