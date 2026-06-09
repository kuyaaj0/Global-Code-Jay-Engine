#pragma once

#include "Modifier.hpp"

class Invert : public Modifier
{
public:

    float percent;

    Invert();

    void apply(Note3D& note, float songPosition) override;
};
