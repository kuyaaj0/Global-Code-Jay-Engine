#include "StateManager.hpp"
#include "../Renderer/Renderer.hpp"

StateManager::StateManager()
{
    currentState = nullptr;
}

StateManager::~StateManager()
{
    if(currentState != nullptr)
    {
        currentState->Shutdown();
        delete currentState;
    }
}

void StateManager::ChangeState(State* nextState)
{
    if(currentState != nullptr)
    {
        currentState->Shutdown();
        delete currentState;
    }

    currentState = nextState;

    if(currentState != nullptr)
    {
        currentState->Initialize();
    }
}

void StateManager::Update(float deltaTime)
{
    if(currentState != nullptr)
        currentState->Update(deltaTime);
}

void StateManager::Render(Renderer* renderer)
{
    if(currentState != nullptr)
        currentState->Render(renderer);
}
