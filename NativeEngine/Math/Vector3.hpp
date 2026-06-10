#pragma once

#include <cmath>

class Vector3
{
public:

    float x;
    float y;
    float z;

    // Constructors
    Vector3();

    Vector3(
        float x,
        float y,
        float z
    );

    // Operators
    Vector3 operator+(const Vector3& other) const;

    Vector3 operator-(const Vector3& other) const;

    Vector3 operator*(float scalar) const;

    Vector3 operator/(float scalar) const;

    bool operator==(const Vector3& other) const;

    bool operator!=(const Vector3& other) const;

    // Math
    float Length() const;

    float LengthSquared() const;

    void Normalize();

    Vector3 Normalized() const;

    // Static Functions
    static float Dot(
        const Vector3& a,
        const Vector3& b
    );

    static Vector3 Cross(
        const Vector3& a,
        const Vector3& b
    );

    static float Distance(
        const Vector3& a,
        const Vector3& b
    );

    static float DistanceSquared(
        const Vector3& a,
        const Vector3& b
    );

    static Vector3 Lerp(
        const Vector3& a,
        const Vector3& b,
        float t
    );
};
