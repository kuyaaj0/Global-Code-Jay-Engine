#pragma once

class Renderer;
class StateManager;

class State
{
public:

    virtual ~State() {}

    virtual bool Initialize() = 0;

    virtual void Update(float deltaTime) = 0;

    void SetStateManager(StateManager* manager)
    {
        stateManager = manager;
    }

    virtual void Render(Renderer* renderer) = 0;

    virtual void Shutdown() = 0;

protected:

    StateManager* stateManager;
};
