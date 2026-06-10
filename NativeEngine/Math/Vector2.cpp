#include "Vector2.hpp"
#include <cmath>

Vector2::Vector2()
{
    x = 0.0f;
    y = 0.0f;
}

Vector2::Vector2(float X,float Y)
{
    x = X;
    y = Y;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(
        x + other.x,
        y + other.y
    );
}

Vector2 Vector2::operator-(const Vector2& other) const
{
    return Vector2(
        x - other.x,
        y - other.y
    );
}

Vector2 Vector2::operator*(float scalar) const
{
    return Vector2(
        x * scalar,
        y * scalar
    );
}

Vector2 Vector2::operator/(float scalar) const
{
    return Vector2(
        x / scalar,
        y / scalar
    );
}

float Vector2::Length() const
{
    return std::sqrt(x*x + y*y);
}

float Vector2::LengthSquared() const
{
    return x*x + y*y;
}

Vector2 Vector2::Normalized() const
{
    float len = Length();

    if(len == 0.0f)
        return Vector2();

    return Vector2(
        x/len,
        y/len
    );
}

float Vector2::Dot(
    const Vector2& a,
    const Vector2& b)
{
    return a.x*b.x + a.y*b.y;
}

float Vector2::Distance(
    const Vector2& a,
    const Vector2& b)
{
    return (a-b).Length();
}

Vector2 Vector2::Lerp(
    const Vector2& a,
    const Vector2& b,
    float t)
{
    return a + (b-a)*t;
}
