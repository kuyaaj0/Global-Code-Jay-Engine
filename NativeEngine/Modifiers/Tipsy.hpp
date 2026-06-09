#pragma once

#include "Modifier.hpp"

class Tipsy : public Modifier
{
public:

    float percent;

    Tipsy();

    void apply(Note3D& note, float songPosition) override;
};
