#pragma once

#include "../../Math/Vector3.hpp"

class Camera3D;

class CameraController
{

public:

    CameraController();

    void SetCamera(
        Camera3D* cam
    );

    void SetTarget(
        const Vector3& position
    );

    void SetZoom(
        float zoom
    );

    void AddShake(
        float intensity
    );

    void Update(
        float deltaTime
    );

private:

    Camera3D* camera;

    Vector3 targetPosition;

    float targetZoom;

    float shakeIntensity;

};
