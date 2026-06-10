#include "Matrix4Renderer.hpp"

Matrix4Renderer::Matrix4Renderer()
{
    activeCamera = nullptr;
}

void Matrix4Renderer::SetCamera(
Camera3D* camera)
{
    activeCamera = camera;
}

Vector4 Matrix4Renderer::ApplyTransform(
const Matrix4& world,
const Vector4& vertex)
{
    return world.Transform(vertex);
}

Vector4 Matrix4Renderer::ApplyView(
const Vector4& vertex)
{
    if(activeCamera == nullptr)
        return vertex;

    return
        activeCamera
        ->GetViewMatrix()
        .Transform(vertex);
}

Vector4 Matrix4Renderer::ApplyProjection(
const Vector4& vertex)
{
    if(activeCamera == nullptr)
        return vertex;

    return
        activeCamera
        ->GetProjectionMatrix()
        .Transform(vertex);
}

Vector4 Matrix4Renderer::WorldToScreen(
const Matrix4& world,
const Vector4& vertex)
{
    Vector4 result =
        ApplyTransform(
            world,
            vertex
        );

    result =
        ApplyView(
            result
        );

    result =
        ApplyProjection(
            result
        );

    return result;
}
