#include "ScoreManager.hpp"

ScoreManager::ScoreManager()
{
    score = 0;
    combo = 0;
    misses = 0;

    marvelousCount = 0;
    sickCount = 0;
    goodCount = 0;
    badCount = 0;
    missCount = 0;
}

void ScoreManager::AddJudge(
JudgeResult result)
{
    switch(result)
    {
        case JudgeResult::Marvelous:
    score += 500;
    combo++;
    marvelousCount++;
    break;
        
        case JudgeResult::Sick:
    score += 350;
    combo++;
    sickCount++;
    break;
        
        case JudgeResult::Good:
    score += 200;
    combo++;
    goodCount++;
    break;
        
        case JudgeResult::Bad:
    score += 50;
    combo = 0;
    badCount++;
    break;
        
        case JudgeResult::Miss:
    combo = 0;
    misses++;
    missCount++;
    break;
    }
}

int ScoreManager::GetScore() const
{
    return score;
}

int ScoreManager::GetCombo() const
{
    return combo;
}

int ScoreManager::GetMisses() const
{
    return misses && missCount;
}

float ScoreManager::GetAccuracy() const
{
    float total =
        marvelousCount +
        sickCount +
        goodCount +
        badCount +
        missCount;

    if(total <= 0)
        return 100.0f;

    float points =
        marvelousCount * 100.0f +
        sickCount * 95.0f +
        goodCount * 80.0f +
        badCount * 50.0f;

    return points / (total * 100.0f) * 100.0f;
}
