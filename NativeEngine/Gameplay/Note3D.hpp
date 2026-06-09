#pragma once

#include "../Math/Vector3.hpp"

#include "../Transform/Transform.hpp"

class Note3D
{
public:

    Transform transform;

    // Position in 3D space
    Vector3 position;

    // Rotation in degrees/radians
    Vector3 rotation;

    // Scale multiplier
    Vector3 scale;

    // FNF lane
    int lane;

    // Visibility
    bool visible;

    // Whether this is a sustain note
    bool sustain;

    // Song timing
    float strumTime;

    Note3D();
};
