#include "Vector3.hpp"

Vector3::Vector3()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector3::Vector3(
    float X,
    float Y,
    float Z
)
{
    x = X;
    y = Y;
    z = Z;
}

Vector3 Vector3::operator+(const Vector3& other) const
{
    return Vector3(
        x + other.x,
        y + other.y,
        z + other.z
    );
}

Vector3 Vector3::operator-(const Vector3& other) const
{
    return Vector3(
        x - other.x,
        y - other.y,
        z - other.z
    );
}

Vector3 Vector3::operator*(float scalar) const
{
    return Vector3(
        x * scalar,
        y * scalar,
        z * scalar
    );
}

Vector3 Vector3::operator/(float scalar) const
{
    return Vector3(
        x / scalar,
        y / scalar,
        z / scalar
    );
}

bool Vector3::operator==(const Vector3& other) const
{
    return x == other.x &&
           y == other.y &&
           z == other.z;
}

bool Vector3::operator!=(const Vector3& other) const
{
    return !(*this == other);
}

float Vector3::Length() const
{
    return std::sqrt(
        x * x +
        y * y +
        z * z
    );
}

float Vector3::LengthSquared() const
{
    return
        x * x +
        y * y +
        z * z;
}

void Vector3::Normalize()
{
    float len = Length();

    if (len == 0.0f)
        return;

    x /= len;
    y /= len;
    z /= len;
}

Vector3 Vector3::Normalized() const
{
    float len = Length();

    if (len == 0.0f)
        return Vector3();

    return Vector3(
        x / len,
        y / len,
        z / len
    );
}

float Vector3::Dot(
    const Vector3& a,
    const Vector3& b
)
{
    return
        a.x * b.x +
        a.y * b.y +
        a.z * b.z;
}

Vector3 Vector3::Cross(
    const Vector3& a,
    const Vector3& b
)
{
    return Vector3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

float Vector3::Distance(
    const Vector3& a,
    const Vector3& b
)
{
    return (a - b).Length();
}

float Vector3::DistanceSquared(
    const Vector3& a,
    const Vector3& b
)
{
    return (a - b).LengthSquared();
}

Vector3 Vector3::Lerp(
    const Vector3& a,
    const Vector3& b,
    float t
)
{
    return a + (b - a) * t;
}
