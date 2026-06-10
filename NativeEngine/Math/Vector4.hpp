#pragma once

#include <cmath>

class Vector4
{
public:

    float x;
    float y;
    float z;
    float w;

    // Constructors
    Vector4();

    Vector4(
        float x,
        float y,
        float z,
        float w
    );

    // Operators
    Vector4 operator+(const Vector4& other) const;

    Vector4 operator-(const Vector4& other) const;

    Vector4 operator*(float scalar) const;

    Vector4 operator/(float scalar) const;

    bool operator==(const Vector4& other) const;

    bool operator!=(const Vector4& other) const;

    // Math
    float Length() const;

    float LengthSquared() const;

    void Normalize();

    Vector4 Normalized() const;

    // Static Functions
    static float Dot(
        const Vector4& a,
        const Vector4& b
    );

    static float Distance(
        const Vector4& a,
        const Vector4& b
    );

    static Vector4 Lerp(
        const Vector4& a,
        const Vector4& b,
        float t
    );
};
