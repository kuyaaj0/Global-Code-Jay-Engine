#pragma once

#include "State.hpp"

#include "../Graphics/Sprite.hpp"
#include "../Graphics/Texture.hpp"
#include "InputManager.hpp"

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

    InputManager* inputManager;

    Sprite logo;

    Texture logoTexture;

    Sprite pressEnter;

    Texture pressTexture;

    float timer;

    bool logoFinished;

    bool waitingForInput;

    bool blinkVisible;

    float blinkTimer;

};
