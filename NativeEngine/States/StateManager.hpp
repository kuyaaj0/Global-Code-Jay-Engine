#pragma once

#include "State.hpp"

class Renderer;
class InputManager;

class StateManager
{

public:

    StateManager(InputManager* input);

    ~StateManager();

    void ChangeState(State* nextState);

    void Update(float deltaTime);

    void Render(Renderer* renderer);

private:

    State* currentState;

    InputManager* inputManager;

};
