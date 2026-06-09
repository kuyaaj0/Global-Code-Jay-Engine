#pragma once

#include "Modifier.hpp"

class Bounce : public Modifier
{
public:

    float percent;
    float amplitude;
    float speed;

    Bounce();

    void apply(Note3D& note, float songPosition) override;
};
