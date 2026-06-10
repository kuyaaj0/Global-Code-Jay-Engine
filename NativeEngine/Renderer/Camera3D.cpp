#include "Camera3D.hpp"

Camera3D::Camera3D()
{
    position = Vector3(0.0f, 0.0f, -10.0f);
    rotation = Vector3(0.0f, 0.0f, 0.0f);
}

Matrix4 Camera3D::getViewMatrix() const
{
    Matrix4 translate =
        Matrix4::Translation(
            -position.x,
            -position.y,
            -position.z
        );

    Matrix4 rotateX =
        Matrix4::RotationX(-rotation.x);

    Matrix4 rotateY =
        Matrix4::RotationY(-rotation.y);

    Matrix4 rotateZ =
        Matrix4::RotationZ(-rotation.z);

    return rotateZ * rotateY * rotateX * translate;
}
