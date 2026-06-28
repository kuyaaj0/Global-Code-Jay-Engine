#pragma once

class Renderer;
class StateManager;
class InputManager;

class State
{
public:

    virtual ~State() {}

    virtual bool Initialize() = 0;

    virtual void Update(float deltaTime) = 0;

    virtual void Render(Renderer* renderer) = 0;

    virtual void Shutdown() = 0;

    void SetStateManager(StateManager* manager)
    {
        stateManager = manager;
    }

    void SetInputManager(InputManager* input)
    {
        inputManager = input;
    }

protected:

    StateManager* stateManager = nullptr;

    InputManager* inputManager = nullptr;
};
