#pragma once

#include "Modifier.hpp"

class Brake : public Modifier
{
public:

    float percent;
    float multiplier;

    Brake();

    void apply(Note3D& note, float songPosition) override;
};
