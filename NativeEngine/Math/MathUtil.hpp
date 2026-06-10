#pragma once

class MathUtil
{
public:

    static float Clamp(
        float value,
        float minimum,
        float maximum
    );

    static float Lerp(
        float a,
        float b,
        float t
    );

    static float Degrees(
        float radians
    );

    static float Radians(
        float degrees
    );

    static float SmoothStep(
        float edge0,
        float edge1,
        float x
    );
};
