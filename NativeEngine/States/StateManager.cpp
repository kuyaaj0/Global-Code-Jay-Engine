#include "StateManager.hpp"
#include "../Renderer/Renderer.hpp"
#include "InputManager.hpp"

StateManager::StateManager(InputManager* input)
{
    currentState = nullptr;

    inputManager = input;
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

    currentState->SetStateManager(this);

    currentState->SetInputManager(inputManager);

    currentState->Initialize();
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
