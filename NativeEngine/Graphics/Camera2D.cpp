#include "Camera2D.hpp"

Camera2D::Camera2D()
{
    position = Vector3(0.0f,0.0f,0.0f);

    zoom = 1.0f;
}

void Camera2D::SetPosition(
const Vector3& pos)
{
    position = pos;
}

void Camera2D::Move(
const Vector3& delta)
{
    position =
        position +
        delta;
}

void Camera2D::SetZoom(
float value)
{
    zoom = value;
}

Vector3 Camera2D::GetPosition() const
{
    return position;
}

float Camera2D::GetZoom() const
{
    return zoom;
}
