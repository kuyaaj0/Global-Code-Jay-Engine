#pragma once

#include "Vector3.hpp"

class Matrix4
{
public:

    float m[16];

    Matrix4();

    static Matrix4 identity();

    static Matrix4 translation(float x, float y, float z);

    static Matrix4 scale(float x, float y, float z);

    static Matrix4 rotationX(float angle);

    static Matrix4 rotationY(float angle);

    static Matrix4 rotationZ(float angle);

    Matrix4 operator*(const Matrix4& other) const;

    Vector3 transformPoint(const Vector3& point) const;
};
