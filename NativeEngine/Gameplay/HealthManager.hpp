#pragma once

class HealthManager
{

public:

    float health;

    float maxHealth;

    bool dead;

    HealthManager();

    void Reset();

    void AddHealth(float amount);

    void RemoveHealth(float amount);

    bool IsDead() const;

};
