#pragma once

#include "../Math/Vector3.hpp"

class StrumLine3D
{
public:

    // Center position of the strumline
    Vector3 position;

    // Rotation of the strumline
    Vector3 rotation;

    // Scale of the strumline
    Vector3 scale;

    // Number of lanes
    int laneCount;

    StrumLine3D();

    Vector3 getLanePosition(int lane);
};
