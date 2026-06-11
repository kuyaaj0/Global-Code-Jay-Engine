#include "HealthManager.hpp"

HealthManager::HealthManager()
{
    Reset();
}

void HealthManager::Reset()
{
    maxHealth = 2.0f;

    health = maxHealth;

    dead = false;
}

void HealthManager::AddHealth(float amount)
{
    health += amount;

    if(health > maxHealth)
        health = maxHealth;
}

void HealthManager::RemoveHealth(float amount)
{
    health -= amount;

    if(health <= 0.0f)
    {
        health = 0.0f;

        dead = true;
    }
}

bool HealthManager::IsDead() const
{
    return dead;
}
