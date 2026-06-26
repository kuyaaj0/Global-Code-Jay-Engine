#pragma once

#include "State.hpp"

class Renderer;

class TitleState : public State
{

public:

    TitleState();

    bool Initialize() override;

    void Update(float deltaTime) override;

    void Render(Renderer* renderer) override;

    void Shutdown() override;

private:

    float timer;

    bool logoFinished;

};
