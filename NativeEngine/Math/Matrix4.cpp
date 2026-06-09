#include "Matrix4.hpp"

Matrix4::Matrix4()
{
    identity();
}

void Matrix4::identity()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            m[i][j]=0.0f;
        }
    }

    m[0][0]=1.0f;
    m[1][1]=1.0f;
    m[2][2]=1.0f;
    m[3][3]=1.0f;
}

Matrix4 Matrix4::createIdentity()
{
    Matrix4 mat;
    mat.identity();
    return mat;
}
