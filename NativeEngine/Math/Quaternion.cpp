#include "Quaternion.hpp"
#include <cmath>

Quaternion::Quaternion()
{
    x=0;
    y=0;
    z=0;
    w=1;
}

Quaternion::Quaternion(
float X,
float Y,
float Z,
float W)
{
    x=X;
    y=Y;
    z=Z;
    w=W;
}

void Quaternion::Normalize()
{
    float len=sqrt(x*x+y*y+z*z+w*w);

    if(len==0)
        return;

    x/=len;
    y/=len;
    z/=len;
    w/=len;
}

Quaternion Quaternion::Normalized() const
{
    Quaternion q=*this;
    q.Normalize();
    return q;
}

Quaternion Quaternion::Identity()
{
    return Quaternion(0,0,0,1);
}

Quaternion Quaternion::operator*(
const Quaternion& b) const
{
    return Quaternion(

        w*b.x+x*b.w+y*b.z-z*b.y,

        w*b.y-x*b.z+y*b.w+z*b.x,

        w*b.z+x*b.y-y*b.x+z*b.w,

        w*b.w-x*b.x-y*b.y-z*b.z

    );
}

Quaternion Quaternion::FromEuler(
float pitch,
float yaw,
float roll)
{
    float cy=cos(yaw*0.5f);
    float sy=sin(yaw*0.5f);

    float cp=cos(pitch*0.5f);
    float sp=sin(pitch*0.5f);

    float cr=cos(roll*0.5f);
    float sr=sin(roll*0.5f);

    Quaternion q;

    q.w=cr*cp*cy+sr*sp*sy;
    q.x=sr*cp*cy-cr*sp*sy;
    q.y=cr*sp*cy+sr*cp*sy;
    q.z=cr*cp*sy-sr*sp*cy;

    return q;
}

Matrix4 Quaternion::ToMatrix() const
{
    Matrix4 mat;
    mat.Identity();

    // Full conversion can be expanded later.

    return mat;
}
