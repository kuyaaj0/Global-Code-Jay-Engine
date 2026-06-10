#include "Matrix4.hpp"
#include <cmath>

Matrix4::Matrix4()
{
    Identity();
}

void Matrix4::Identity()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            m[i][j]=0.0f;
        }

        m[i][i]=1.0f;
    }
}

Matrix4 Matrix4::IdentityMatrix()
{
    Matrix4 mat;
    mat.Identity();
    return mat;
}

Matrix4 Matrix4::Translation(
    float x,
    float y,
    float z)
{
    Matrix4 mat;

    mat.m[0][3]=x;
    mat.m[1][3]=y;
    mat.m[2][3]=z;

    return mat;
}

Matrix4 Matrix4::Scale(
    float x,
    float y,
    float z)
{
    Matrix4 mat;

    mat.m[0][0]=x;
    mat.m[1][1]=y;
    mat.m[2][2]=z;

    return mat;
}

Matrix4 Matrix4::RotationX(float angle)
{
    Matrix4 mat;

    float c=cos(angle);
    float s=sin(angle);

    mat.m[1][1]=c;
    mat.m[1][2]=-s;
    mat.m[2][1]=s;
    mat.m[2][2]=c;

    return mat;
}

Matrix4 Matrix4::RotationY(float angle)
{
    Matrix4 mat;

    float c=cos(angle);
    float s=sin(angle);

    mat.m[0][0]=c;
    mat.m[0][2]=s;
    mat.m[2][0]=-s;
    mat.m[2][2]=c;

    return mat;
}

Matrix4 Matrix4::RotationZ(float angle)
{
    Matrix4 mat;

    float c=cos(angle);
    float s=sin(angle);

    mat.m[0][0]=c;
    mat.m[0][1]=-s;
    mat.m[1][0]=s;
    mat.m[1][1]=c;

    return mat;
}

Matrix4 Matrix4::operator*(const Matrix4& other) const
{
    Matrix4 result;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            result.m[i][j]=0.0f;

            for(int k=0;k<4;k++)
            {
                result.m[i][j]+=m[i][k]*other.m[k][j];
            }
        }
    }

    return result;
}

Vector4 Matrix4::Transform(const Vector4& v) const
{
    return Vector4(

        m[0][0]*v.x+m[0][1]*v.y+m[0][2]*v.z+m[0][3]*v.w,

        m[1][0]*v.x+m[1][1]*v.y+m[1][2]*v.z+m[1][3]*v.w,

        m[2][0]*v.x+m[2][1]*v.y+m[2][2]*v.z+m[2][3]*v.w,

        m[3][0]*v.x+m[3][1]*v.y+m[3][2]*v.z+m[3][3]*v.w

    );
}
