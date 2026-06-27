#pragma once

#include "../Math/Vector3.hpp"

class Texture;

class Sprite
{

public:

    Sprite();

    Vector3 position;

    Vector3 scale;

    float rotation;

    Texture* texture;

    void Draw(Renderer* renderer);

};
