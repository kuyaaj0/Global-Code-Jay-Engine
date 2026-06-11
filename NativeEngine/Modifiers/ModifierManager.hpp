#pragma once

#include "../Gameplay/Note3D.hpp"

class ModifierManager
{

public:

    float reverse;

    float drunk;

    float tipsy;

    float tornado;

    float zigzag;

    float bounce;

    float mini;

    float hidden;

    float sudden;

    float boost;

    float brake;

    float wave;

    float flip;

    float invert;

    float xmod;

    float cmod;

    float mmod;

    float perspective;

    float rotateX;

    float rotateY;

    float rotateZ;

    ModifierManager();

    void Reset();

    void Apply(
        Note3D& note,
        float songPosition
    );

};
