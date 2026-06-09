#pragma once

#include "Modifier.hpp"

class Boost : public Modifier
{
public:

    float percent;
    float multiplier;

    Boost();

    void apply(Note3D& note, float songPosition) override;
};
