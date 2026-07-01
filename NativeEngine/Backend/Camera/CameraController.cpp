#include "CameraController.hpp"

#include "../../Renderer/Camera3D.hpp"
#include "../Utils/CamUtil.hpp"
//#include "../../Transform/Transform.hpp"
#include "../../Object/Character.hpp"

CameraController::CameraController()
{
    camera = nullptr;
    targetCharacter = nullptr;

    targetPosition = Vector3(
        0.0f,
        0.0f,
        0.0f
    );

    targetFOV = 70.0f;

    shakeIntensity = 0.0f;
}

void CameraController::FollowCharacter(
Character* character)
{
    targetCharacter = character;
}

void CameraController::SetCamera(
Camera3D* cam)
{
    camera = cam;
}

void CameraController::SetTarget(
const Vector3& position)
{
    focusPosition = position;
}

void CameraController::SetFOV(
float fov)
{
    targetFOV = fov;
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

    if(targetCharacter != nullptr)
    {
        focusPosition =
            targetCharacter->GetCameraFocus();
    }

    camera->transform.SetPosition(
        CamUtil::LerpPosition(
            camera->transform.GetPosition(),
            targetPosition,
            deltaTime * 6.0f
        )
    );

    camera->SetFOV(
        CamUtil::Lerp(
            camera->fov,
            targetFOV,
            deltaTime * 6.0f
        )
    );

    camera->UpdateView();

    if(shakeIntensity > 0.0f)
    {
        shakeIntensity -= deltaTime * 4.0f;

        if(shakeIntensity < 0.0f)
            shakeIntensity = 0.0f;
    }
}
