#include "Vector4.hpp"

Vector4::Vector4()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}

Vector4::Vector4(
    float X,
    float Y,
    float Z,
    float W
)
{
    x = X;
    y = Y;
    z = Z;
    w = W;
}

Vector4 Vector4::operator+(const Vector4& other) const
{
    return Vector4(
        x + other.x,
        y + other.y,
        z + other.z,
        w + other.w
    );
}

Vector4 Vector4::operator-(const Vector4& other) const
{
    return Vector4(
        x - other.x,
        y - other.y,
        z - other.z,
        w - other.w
    );
}

Vector4 Vector4::operator*(float scalar) const
{
    return Vector4(
        x * scalar,
        y * scalar,
        z * scalar,
        w * scalar
    );
}

Vector4 Vector4::operator/(float scalar) const
{
    return Vector4(
        x / scalar,
        y / scalar,
        z / scalar,
        w / scalar
    );
}

bool Vector4::operator==(const Vector4& other) const
{
    return
        x == other.x &&
        y == other.y &&
        z == other.z &&
        w == other.w;
}

bool Vector4::operator!=(const Vector4& other) const
{
    return !(*this == other);
}

float Vector4::Length() const
{
    return std::sqrt(
        x*x +
        y*y +
        z*z +
        w*w
    );
}

float Vector4::LengthSquared() const
{
    return
        x*x +
        y*y +
        z*z +
        w*w;
}

void Vector4::Normalize()
{
    float len = Length();

    if(len == 0.0f)
        return;

    x /= len;
    y /= len;
    z /= len;
    w /= len;
}

Vector4 Vector4::Normalized() const
{
    float len = Length();

    if(len == 0.0f)
        return Vector4();

    return Vector4(
        x/len,
        y/len,
        z/len,
        w/len
    );
}

float Vector4::Dot(
    const Vector4& a,
    const Vector4& b
)
{
    return
        a.x*b.x +
        a.y*b.y +
        a.z*b.z +
        a.w*b.w;
}

float Vector4::Distance(
    const Vector4& a,
    const Vector4& b
)
{
    return (a-b).Length();
}

Vector4 Vector4::Lerp(
    const Vector4& a,
    const Vector4& b,
    float t
)
{
    return a + (b-a)*t;
}
