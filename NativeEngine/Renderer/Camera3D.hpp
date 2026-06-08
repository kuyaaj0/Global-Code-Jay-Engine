#pragma once

#include "../Math/Vector3.hpp"
#include "../Math/Matrix4.hpp"

class Camera3D
{
public:

    Vector3 position;
    Vector3 rotation;

    Camera3D();

    Matrix4 getViewMatrix() const;
};
