#pragma once

#include "../Math/Vector3.hpp"
#include "../Math/Quaternion.hpp"
#include "../Math/Matrix4.hpp"

class Transform
{
public:

    // Position
    Vector3 position;

    // Rotation
    Quaternion rotation;

    // Scale
    Vector3 scale;

    // Cached matrices
    Matrix4 localMatrix;
    Matrix4 worldMatrix;

    // Constructor
    Transform();

    // Update matrices
    void Update();

    // Position
    void SetPosition(
        const Vector3& pos
    );

    void Translate(
        const Vector3& delta
    );

    // Rotation
    void SetRotation(
        const Quaternion& rot
    );

    void Rotate(
        const Quaternion& delta
    );

    // Scale
    void SetScale(
        const Vector3& scl
    );

    // Reset
    void Reset();

    // Get final transform matrix
    Matrix4 GetMatrix() const;
};
