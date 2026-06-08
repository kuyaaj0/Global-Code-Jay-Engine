#include "Matrix4.hpp"

#include <cmath>

Matrix4::Matrix4()
{
    for(int i = 0; i < 16; i++)
        m[i] = 0.0f;
}

Matrix4 Matrix4::identity()
{
    Matrix4 result;

    result.m[0] = 1.0f;
    result.m[5] = 1.0f;
    result.m[10] = 1.0f;
    result.m[15] = 1.0f;

    return result;
}

Matrix4 Matrix4::translation(float x, float y, float z)
{
    Matrix4 result = identity();

    result.m[12] = x;
    result.m[13] = y;
    result.m[14] = z;

    return result;
}

Matrix4 Matrix4::scale(float x, float y, float z)
{
    Matrix4 result = identity();

    result.m[0] = x;
    result.m[5] = y;
    result.m[10] = z;

    return result;
}

Matrix4 Matrix4::rotationX(float angle)
{
    Matrix4 result = identity();

    float c = std::cos(angle);
    float s = std::sin(angle);

    result.m[5] = c;
    result.m[6] = s;

    result.m[9] = -s;
    result.m[10] = c;

    return result;
}

Matrix4 Matrix4::rotationY(float angle)
{
    Matrix4 result = identity();

    float c = std::cos(angle);
    float s = std::sin(angle);

    result.m[0] = c;
    result.m[2] = -s;

    result.m[8] = s;
    result.m[10] = c;

    return result;
}

Matrix4 Matrix4::rotationZ(float angle)
{
    Matrix4 result = identity();

    float c = std::cos(angle);
    float s = std::sin(angle);

    result.m[0] = c;
    result.m[1] = s;

    result.m[4] = -s;
    result.m[5] = c;

    return result;
}

Matrix4 Matrix4::operator*(const Matrix4& other) const
{
    Matrix4 result;

    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            result.m[row * 4 + col] =

                m[row * 4 + 0] * other.m[col + 0] +
                m[row * 4 + 1] * other.m[col + 4] +
                m[row * 4 + 2] * other.m[col + 8] +
                m[row * 4 + 3] * other.m[col + 12];
        }
    }

    return result;
}

Vector3 Matrix4::transformPoint(const Vector3& point) const
{
    Vector3 result;

    result.x =
        point.x * m[0] +
        point.y * m[4] +
        point.z * m[8] +
        m[12];

    result.y =
        point.x * m[1] +
        point.y * m[5] +
        point.z * m[9] +
        m[13];

    result.z =
        point.x * m[2] +
        point.y * m[6] +
        point.z * m[10] +
        m[14];

    return result;
}
