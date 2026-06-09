#pragma once

#include "../Gameplay/Note3D.hpp"

class Modifier
{
public:

    virtual ~Modifier() {}

    virtual void apply(
        Note3D& note,
        float songPosition
    ) = 0;
};
