#include "Sprite.hpp"

Sprite::Sprite()
{
    position = Vector3(0.0f,0.0f,0.0f);

    scale = Vector3(1.0f,1.0f,1.0f);

    rotation = 0.0f;

    texture = nullptr;
}

void Sprite::Draw(Renderer* renderer)
{
    if(renderer == nullptr)
        return;

    if(texture == nullptr)
        return;

    Matrix4 world;

    world.Identity();

    world.Translate(
        position.x,
        position.y,
        position.z
    );

    world.Scale(
        scale.x,
        scale.y,
        scale.z
    );

    // Rotation will be added later

    Vector4 quad[4] =
    {
        Vector4(-0.5f,-0.5f,0.0f,1.0f),
        Vector4( 0.5f,-0.5f,0.0f,1.0f),
        Vector4( 0.5f, 0.5f,0.0f,1.0f),
        Vector4(-0.5f, 0.5f,0.0f,1.0f)
    };

    renderer->DrawQuad(
        world,
        quad
    );
}
