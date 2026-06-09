#pragma once

#include "Modifier.hpp"

class RotateX : public Modifier
{
public:

    float angle;

    RotateX();

    void apply(Note3D& note, float songPosition) override;
};
