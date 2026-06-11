#include "CameraManager.hpp"

CameraManager::CameraManager()
{
    position = Vector3(0.0f,0.0f,0.0f);

    zoom = 1.0f;
}

void CameraManager::SetPosition(
const Vector3& pos)
{
    position = pos;
}

void CameraManager::Move(
const Vector3& delta)
{
    position =
        position +
        delta;
}

void CameraManager::SetZoom(
float value)
{
    zoom = value;
}

Vector3 CameraManager::GetPosition() const
{
    return position;
}

float CameraManager::GetZoom() const
{
    return zoom;
}
