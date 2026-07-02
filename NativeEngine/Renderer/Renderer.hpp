#pragma once

#include "Matrix4Renderer.hpp"
#include "Camera3D.hpp"
#include "../Math/Matrix4.hpp"
#include "../Math/Vector4.hpp"

class Texture;
class Sprite;

class Renderer
{

public:

    Renderer();

    void SetCamera(
        Camera3D* camera
    );

    void BeginFrame();

    void EndFrame();

    void Clear();

    void DrawVertex(
        const Matrix4& world,
        const Vector4& vertex
    );

    void DrawQuad(
    const Matrix4& world,
    const Vector4 vertices[4],
    Texture* texture,
    float frameX,
    float frameY,
    float frameWidth,
    float frameHeight
);

    void DrawNote(
        const Matrix4& world,
        const Vector4 vertices[4]
    );

    void DrawSprite(
    Texture* texture,
    const Matrix4& world
);

private:

    Matrix4Renderer matrixRenderer;

    Camera3D* activeCamera;

};
