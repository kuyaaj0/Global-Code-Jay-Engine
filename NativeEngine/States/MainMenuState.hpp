#pragma once

#include "State.hpp"

class Renderer;

class MainMenuState : public State
{

public:

    MainMenuState();

    bool Initialize() override;

    void Update(float deltaTime) override;

    void Render(Renderer* renderer) override;

    void Shutdown() override;

private:

    int currentSelection;

};
