#pragma once

#include "Matrix4.hpp"

class Quaternion
{
public:

    float x;
    float y;
    float z;
    float w;

    Quaternion();

    Quaternion(
        float x,
        float y,
        float z,
        float w
    );

    void Normalize();

    Quaternion Normalized() const;

    Quaternion operator*(const Quaternion& other) const;

    static Quaternion Identity();

    static Quaternion FromEuler(
        float pitch,
        float yaw,
        float roll
    );

    Matrix4 ToMatrix() const;
};
