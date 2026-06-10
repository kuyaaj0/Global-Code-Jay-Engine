#include "Transform.hpp"

Transform::Transform()
{
    position = Vector3(0,0,0);

    rotation = Quaternion::Identity();

    scale = Vector3(1,1,1);

    UpdateMatrix();
}

void Transform::UpdateMatrix()
{
    Matrix4 T =
        Matrix4::Translation(
            position.x,
            position.y,
            position.z
        );

    Matrix4 R =
        rotation.ToMatrix();

    Matrix4 S =
        Matrix4::Scale(
            scale.x,
            scale.y,
            scale.z
        );

    localMatrix =
        T * R * S;

    worldMatrix =
        localMatrix;
}

void Transform::Translate(
const Vector3& delta)
{
    position =
        position + delta;

    UpdateMatrix();
}

void Transform::Rotate(
const Quaternion& delta)
{
    rotation =
        rotation * delta;

    rotation.Normalize();

    UpdateMatrix();
}

void Transform::SetScale(
const Vector3& newScale)
{
    scale =
        newScale;

    UpdateMatrix();
}
