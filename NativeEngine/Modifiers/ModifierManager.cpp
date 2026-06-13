#include "ModifierManager.hpp"

#include <cmath>

ModifierManager::ModifierManager()
{
    reverse = 0.0f;
    boost = 0.0f;
    brake = 0.0f;
    wave = 0.0f;
    mini = 0.0f;
    flip = 0.0f;
}

void ModifierManager::SetReverse(float value)
{
    reverse = value;
}

void ModifierManager::SetBoost(float value)
{
    boost = value;
}

void ModifierManager::SetBrake(float value)
{
    brake = value;
}

void ModifierManager::SetWave(float value)
{
    wave = value;
}

void ModifierManager::SetMini(float value)
{
    mini = value;
}

void ModifierManager::SetFlip(float value)
{
    flip = value;
}

Vector3 ModifierManager::Apply(
int lane,
float distance,
const Vector3 position)
{
    if(reverse > 0.0f)
    {
        position.y = -position.y;
    }

    position.y += distance * boost;

    position.y -= distance * brake;

    position.x +=
        std::sin(distance * 0.01f)
        * 50.0f
        * wave;

    position.x *=
        (1.0f - mini * 0.5f);

    if(flip > 0.0f)
    {
        position.x = -position.x;
    }

    return position;
}
