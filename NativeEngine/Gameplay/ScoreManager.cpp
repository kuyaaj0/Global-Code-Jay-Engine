#include "ScoreManager.hpp"

ScoreManager::ScoreManager()
{
    Reset();
}

void ScoreManager::Reset()
{
    score = 0;
    combo = 0;
    misses = 0;
    maxCombo = 0;
    accuracy = 100.0f;
}

void ScoreManager::AddScore(int value)
{
    score += value;
}

void ScoreManager::AddCombo()
{
    combo++;

    if(combo > maxCombo)
        maxCombo = combo;
}

void ScoreManager::BreakCombo()
{
    combo = 0;
}

void ScoreManager::RegisterHit(float rating)
{
    AddCombo();

    score += (int)(350 * rating);
}

void ScoreManager::RegisterMiss()
{
    misses++;

    BreakCombo();
}
