#pragma once

class Renderer;

class State
{
public:

    virtual ~State() {}

    virtual bool Initialize() = 0;

    virtual void Update(float deltaTime) = 0;

    virtual void Render(Renderer* renderer) = 0;

    virtual void Shutdown() = 0;
};
