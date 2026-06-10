#pragma once

#include "../Math/Vector3.hpp"
#include "../Math/Quaternion.hpp"
#include "../Math/Matrix4.hpp"

class Transform
{

public:

    Vector3 position;

    Quaternion rotation;

    Vector3 scale;

    Matrix4 localMatrix;

    Matrix4 worldMatrix;

    Transform();

    void UpdateMatrix();

    void Translate(
        const Vector3& delta
    );

    void Rotate(
        const Quaternion& delta
    );

    void SetScale(
        const Vector3& newScale
    );

};
