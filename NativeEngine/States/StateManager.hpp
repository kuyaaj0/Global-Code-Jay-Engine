#pragma once

#include "State.hpp"

class Renderer;

class StateManager
{

public:

    StateManager();

    ~StateManager();

    void ChangeState(State* nextState);

    void Update(float deltaTime);

    void Render(Renderer* renderer);

private:

    State* currentState;

};
