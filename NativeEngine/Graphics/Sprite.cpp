#include "Sprite.hpp"

Sprite::Sprite()
{
    position = Vector3(0.0f,0.0f,0.0f);

    scale = Vector3(1.0f,1.0f,1.0f);

    rotation = 0.0f;

    texture = nullptr;
}

void Sprite::Draw()
{
    // Future:
    // Render sprite
}
