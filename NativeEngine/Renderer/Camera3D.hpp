#pragma once

#include "../Core/Transform.hpp"
#include "../Math/Matrix4.hpp"
#include "../Math/Vector3.hpp"

class Camera3D
{
public:

    Transform transform;

    float fov;
    float nearPlane;
    float farPlane;
    float aspectRatio;

    Matrix4 viewMatrix;
    Matrix4 projectionMatrix;

    Camera3D();

    void Update();

    void UpdateView();

    void UpdateProjection();

    void SetAspectRatio(
        float aspect
    );

    void SetFOV(
        float value
    );

    void Move(
        const Vector3& delta
    );

    void LookAt(
        const Vector3& target
    );

    Matrix4 GetViewMatrix() const;

    Matrix4 GetProjectionMatrix() const;
};
