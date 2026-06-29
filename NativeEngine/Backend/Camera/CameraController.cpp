#include "CameraController.hpp"

#include "../../Renderer/Camera3D.hpp"
#include "../Utils/CamUtil.hpp"

CameraController::CameraController()
{
    camera = nullptr;

    targetPosition = Vector3(
        0.0f,
        0.0f,
        0.0f
    );

    targetZoom = 1.0f;

    shakeIntensity = 0.0f;
}

void CameraController::SetCamera(
Camera3D* cam)
{
    camera = cam;
}

void CameraController::SetTarget(
const Vector3& position)
{
    targetPosition = position;
}

void CameraController::SetZoom(
float zoom)
{
    targetZoom = zoom;
}

void CameraController::AddShake(
float intensity)
{
    shakeIntensity += intensity;
}

void CameraController::Update(
float deltaTime)
{
    if(camera == nullptr)
        return;

    // Smooth camera follow
    camera->position =
        CamUtil::LerpPosition(
            camera->position,
            targetPosition,
            deltaTime * 6.0f
        );

    // Smooth zoom
    camera->zoom =
        CamUtil::Lerp(
            camera->zoom,
            targetZoom,
            deltaTime * 6.0f
        );

    camera->zoom =
        CamUtil::ClampZoom(
            camera->zoom,
            0.5f,
            3.0f
        );

    // Temporary shake decay
    if(shakeIntensity > 0.0f)
    {
        shakeIntensity -= deltaTime * 4.0f;

        if(shakeIntensity < 0.0f)
            shakeIntensity = 0.0f;
    }
}
