#include "MathUtil.hpp"
#include <cmath>

float MathUtil::Clamp(
float value,
float minimum,
float maximum)
{
    if(value<minimum)
        return minimum;

    if(value>maximum)
        return maximum;

    return value;
}

float MathUtil::Lerp(
float a,
float b,
float t)
{
    return a+(b-a)*t;
}

float MathUtil::Degrees(
float radians)
{
    return radians*180.0f/3.1415926535f;
}

float MathUtil::Radians(
float degrees)
{
    return degrees*3.1415926535f/180.0f;
}

float MathUtil::SmoothStep(
float edge0,
float edge1,
float x)
{
    x=Clamp(
        (x-edge0)/(edge1-edge0),
        0.0f,
        1.0f
    );

    return x*x*(3.0f-2.0f*x);
}
