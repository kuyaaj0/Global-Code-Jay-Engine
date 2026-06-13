#pragma once

#include "JudgeResult.hpp"

class HealthManager
{

public:

    HealthManager();

    void ApplyJudge(
        JudgeResult result
    );

    float GetHealth() const;

private:

    float health;

};
