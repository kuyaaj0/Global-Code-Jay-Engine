#pragma once

class Vector2
{
public:

    float x;
    float y;

    Vector2();

    Vector2(float x, float y);

    Vector2 operator+(const Vector2& other) const;

    Vector2 operator-(const Vector2& other) const;

    Vector2 operator*(float scalar) const;

    Vector2 operator/(float scalar) const;

    float Length() const;

    float LengthSquared() const;

    Vector2 Normalized() const;

    static float Dot(const Vector2& a, const Vector2& b);

    static float Distance(const Vector2& a, const Vector2& b);

    static Vector2 Lerp(
        const Vector2& a,
        const Vector2& b,
        float t
    );
};
