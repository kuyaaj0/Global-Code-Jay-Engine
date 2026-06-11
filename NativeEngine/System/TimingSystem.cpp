#include "TimingSystem.hpp"

TimingSystem::TimingSystem()
{
    Reset();
}

void TimingSystem::Reset()
{
    deltaTime = 0.0f;
    elapsedTime = 0.0f;
}

void TimingSystem::Update(
float dt)
{
    deltaTime = dt;
    elapsedTime += dt;
}

float TimingSystem::GetDeltaTime() const
{
    return deltaTime;
}

float TimingSystem::GetElapsedTime() const
{
    return elapsedTime;
}
