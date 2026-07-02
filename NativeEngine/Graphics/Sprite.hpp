#pragma once

#include "../Math/Vector3.hpp"
#include "../Renderer/Renderer.hpp"

class Texture;

class Sprite
{

public:

    Sprite();

    Vector3 position;

    Vector3 scale;

    float rotation;

    Texture* texture;

    int frameIndex;

    float frameWidth;
    float frameHeight;

    float frameX;
    float frameY;

    void SetFrame(int frame);

    void Draw(Renderer* renderer);

};
