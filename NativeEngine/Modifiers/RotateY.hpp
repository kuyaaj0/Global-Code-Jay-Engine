#pragma once

#include "Modifier.hpp"

class RotateY : public Modifier
{
public:

    float angle;

    RotateY();

    void apply(Note3D& note, float songPosition) override;
};
