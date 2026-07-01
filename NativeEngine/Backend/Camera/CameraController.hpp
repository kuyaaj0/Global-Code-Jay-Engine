#pragma once

#include "../../Math/Vector3.hpp"

class Character;
class Camera3D;

class CameraController
{

public:

    CameraController();

    void FollowCharacter(
    Character* character
);

    void SetCamera(
        Camera3D* cam
    );

    void SetTarget(
        const Vector3& position
    );

    void SetFOV(
    float fov
);

    void AddShake(
        float intensity
    );

    void Update(
        float deltaTime
    );

private:

    Character* targetCharacter;

    Camera3D* camera;

    Vector3 targetPosition;

    float targetFOV;

    float shakeIntensity;

};
