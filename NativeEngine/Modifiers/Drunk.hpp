#pragma once

#include "Modifier.hpp"

class Drunk : public Modifier
{
public:

    float percent;
    float speed;
    float spacing;

    Drunk();

    void apply(Note3D& note, float songPosition) override;
};
