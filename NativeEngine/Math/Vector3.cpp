#include "Vector3.hpp"

Vector3::Vector3()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector3::Vector3(float X,float Y,float Z)
{
    x = X;
    y = Y;
    z = Z;
}

Vector3 Vector3::operator+(const Vector3& other)
{
    return Vector3(
        x + other.x,
        y + other.y,
        z + other.z
    );
}

Vector3 Vector3::operator-(const Vector3& other)
{
    return Vector3(
        x - other.x,
        y - other.y,
        z - other.z
    );
}

Vector3 Vector3::operator*(float value)
{
    return Vector3(
        x * value,
        y * value,
        z * value
    );
}
