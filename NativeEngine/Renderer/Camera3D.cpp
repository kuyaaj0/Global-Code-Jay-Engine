#include "Camera3D.hpp"

Camera3D::Camera3D()
{
    fov = 70.0f;

    nearPlane = 0.1f;

    farPlane = 1000.0f;

    aspectRatio = 16.0f / 9.0f;

    Update();
}

void Camera3D::Update()
{
    UpdateView();

    UpdateProjection();
}

void Camera3D::UpdateView()
{
    transform.Update();

    viewMatrix =
        transform.GetMatrix();
}

void Camera3D::UpdateProjection()
{
    projectionMatrix =
        Matrix4::IdentityMatrix();

    // Perspective projection will be expanded later
}

void Camera3D::SetAspectRatio(
float aspect)
{
    aspectRatio = aspect;

    UpdateProjection();
}

void Camera3D::SetFOV(
float value)
{
    fov = value;

    UpdateProjection();
}

void Camera3D::Move(
const Vector3& delta)
{
    transform.Translate(delta);

    UpdateView();
}

void Camera3D::LookAt(
const Vector3& target)
{
    // Placeholder
    // Future implementation:
    // Compute forward/right/up vectors
    // Build view matrix
}

Matrix4 Camera3D::GetViewMatrix() const
{
    return viewMatrix;
}

Matrix4 Camera3D::GetProjectionMatrix() const
{
    return projectionMatrix;
}
