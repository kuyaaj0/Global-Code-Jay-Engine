#pragma once

#include "Modifier.hpp"

class Reverse : public Modifier
{
public:

    float percent;

    Reverse();

    void apply(Note3D& note, float songPosition) override;
};
