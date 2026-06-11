#pragma once

#include "Matrix4Renderer.hpp"
#include "Camera3D.hpp"
#include "../Math/Matrix4.hpp"
#include "../Math/Vector4.hpp"

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
        const Vector4 vertices[4]
    );

    void DrawNote(
        const Matrix4& world,
        const Vector4 vertices[4]
    );

private:

    Matrix4Renderer matrixRenderer;

    Camera3D* activeCamera;

};
