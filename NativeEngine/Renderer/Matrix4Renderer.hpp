#pragma once

#include "../Math/Matrix4.hpp"
#include "../Math/Vector4.hpp"
#include "Camera3D.hpp"

class Matrix4Renderer
{

public:

    Camera3D* activeCamera;

    Matrix4Renderer();

    void SetCamera(
        Camera3D* camera
    );

    Vector4 ApplyTransform(
        const Matrix4& world,
        const Vector4& vertex
    );

    Vector4 ApplyView(
        const Vector4& vertex
    );

    Vector4 ApplyProjection(
        const Vector4& vertex
    );

    Vector4 WorldToScreen(
        const Matrix4& world,
        const Vector4& vertex
    );
};
