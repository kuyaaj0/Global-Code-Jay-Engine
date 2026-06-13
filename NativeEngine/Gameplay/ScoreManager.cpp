#include "ScoreManager.hpp"

ScoreManager::ScoreManager()
{
    score = 0;

    combo = 0;
}

void ScoreManager::AddJudge(
JudgeResult result)
{
    switch(result)
    {
        case JudgeResult::Marvelous:
            score += 350;
            combo++;
            break;

        case JudgeResult::Sick:
            score += 300;
            combo++;
            break;

        case JudgeResult::Good:
            score += 200;
            combo++;
            break;

        case JudgeResult::Bad:
            score += 50;
            combo = 0;
            break;

        case JudgeResult::Miss:
            combo = 0;
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
