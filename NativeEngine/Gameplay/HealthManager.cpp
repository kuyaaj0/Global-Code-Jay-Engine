#include "HealthManager.hpp"

HealthManager::HealthManager()
{
    health = 1.0f;
}

void HealthManager::ApplyJudge(
JudgeResult result)
{
    switch(result)
    {
        case JudgeResult::Marvelous:
        case JudgeResult::Sick:
            health += 0.02f;
            break;

        case JudgeResult::Good:
            health += 0.01f;
            break;

        case JudgeResult::Bad:
            health -= 0.03f;
            break;

        case JudgeResult::Miss:
            health -= 0.08f;
            break;
    }

    if(health > 2.0f)
        health = 2.0f;

    if(health < 0.0f)
        health = 0.0f;
}

float HealthManager::GetHealth() const
{
    return health;
}
