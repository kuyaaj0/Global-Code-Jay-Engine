#pragma once

#include "Modifier.hpp"

class RotateZ : public Modifier
{
public:

    float angle;

    RotateZ();

    void apply(Note3D& note, float songPosition) override;
};
