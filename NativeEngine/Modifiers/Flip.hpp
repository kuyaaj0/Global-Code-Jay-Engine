#pragma once

#include "Modifier.hpp"

class Flip : public Modifier
{
public:

    float percent;

    Flip();

    void apply(Note3D& note, float songPosition) override;
};
