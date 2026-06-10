#pragma once

#include "Vector3.hpp"
#include "Vector4.hpp"

class Matrix4
{
public:

    float m[4][4];

    Matrix4();

    void Identity();

    static Matrix4 IdentityMatrix();

    static Matrix4 Translation(
        float x,
        float y,
        float z
    );

    static Matrix4 Scale(
        float x,
        float y,
        float z
    );

    static Matrix4 RotationX(float angle);

    static Matrix4 RotationY(float angle);

    static Matrix4 RotationZ(float angle);

    Matrix4 operator*(const Matrix4& other) const;

    Vector4 Transform(const Vector4& vec) const;
};
