#pragma once

class ScoreManager
{

public:

    int score;

    int combo;

    int misses;

    int maxCombo;

    float accuracy;

    ScoreManager();

    void Reset();

    void AddScore(int value);

    void AddCombo();

    void BreakCombo();

    void RegisterHit(float rating);

    void RegisterMiss();

};
