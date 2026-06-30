#include "Transform.hpp"

Transform::Transform()
{
    Reset();
}

Vector3 Transform::GetPosition() const
{
    return position;
}

Quaternion Transform::GetRotation() const
{
    return rotation;
}

Vector3 Transform::GetScale() const
{
    return scale;
}

void Transform::Reset()
{
    position = Vector3(0.0f, 0.0f, 0.0f);

    rotation = Quaternion::Identity();

    scale = Vector3(1.0f, 1.0f, 1.0f);

    Update();
}

void Transform::Update()
{
    Matrix4 translation =
        Matrix4::Translation(
            position.x,
            position.y,
            position.z
        );

    Matrix4 rotationMatrix =
        rotation.ToMatrix();

    Matrix4 scaleMatrix =
        Matrix4::Scale(
            scale.x,
            scale.y,
            scale.z
        );

    localMatrix =
        translation *
        rotationMatrix *
        scaleMatrix;

    worldMatrix = localMatrix;
}

void Transform::SetPosition(
const Vector3& pos)
{
    position = pos;
    Update();
}

void Transform::Translate(
const Vector3& delta)
{
    position =
        position + delta;

    Update();
}

void Transform::SetRotation(
const Quaternion& rot)
{
    rotation = rot;
    rotation.Normalize();

    Update();
}

void Transform::Rotate(
const Quaternion& delta)
{
    rotation =
        rotation * delta;

    rotation.Normalize();

    Update();
}

void Transform::SetScale(
const Vector3& scl)
{
    scale = scl;
    Update();
}

Matrix4 Transform::GetMatrix() const
{
    return worldMatrix;
}
