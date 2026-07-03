#pragma once

#include "../Math/Matrix4.hpp"
#include "../Graphics/Texture.hpp"
#include "../Graphics/AtlasFrame.hpp"

class Renderer;

class SpriteRenderer
{

public:

    SpriteRenderer();

    void Draw(
        Renderer* renderer,
        Texture* texture,
        const AtlasFrame& frame,
        const Matrix4& world
    );

};
