#include "Sprite.hpp"
#include "Texture.hpp"

Sprite::Sprite()
{
    position = Vector3(0.0f,0.0f,0.0f);

    scale = Vector3(1.0f,1.0f,1.0f);

    rotation = 0.0f;

    texture = nullptr;

    frameIndex = 0;

    frameWidth = 0.0f;

    frameHeight = 0.0f;

    frameX = 0.0f;

    frameY = 0.0f;
}

void Sprite::SetFrame(int frame)
{
    frameIndex = frame;
}

void Sprite::Draw(Renderer* renderer)
{
    if(renderer == nullptr)
        return;

    if(texture == nullptr)
        return;

    Matrix4 world =
        Matrix4::Translation(
            position.x,
            position.y,
            position.z
        )
        *
        Matrix4::RotationZ(rotation)
        *
        Matrix4::Scale(
            scale.x,
            scale.y,
            scale.z
        );

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
