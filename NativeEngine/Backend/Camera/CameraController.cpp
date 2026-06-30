#include "CameraController.hpp"

#include "../../Renderer/Camera3D.hpp"
#include "../Utils/CamUtil.hpp"
#include "../../Transform/Transform.hpp"

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
    camera->transform.SetPosition(
    CamUtil::LerpPosition(
        camera->transform.GetPosition(),
        targetPosition,
        deltaTime * 6.0f
    )
);

    // Smooth zoom
    camera->SetFOV(
    CamUtil::Lerp(
        camera->fov,
        targetFOV,
        deltaTime * 6.0f
    )
);

    camera->SetFOV(
    camera->fov
);
    camera->UpdateView();

    // Temporary shake decay
    if(shakeIntensity > 0.0f)
    {
        shakeIntensity -= deltaTime * 4.0f;

        if(shakeIntensity < 0.0f)
            shakeIntensity = 0.0f;
    }
}
