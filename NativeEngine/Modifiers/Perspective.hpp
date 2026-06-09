#pragma once

#include "Modifier.hpp"

class Perspective : public Modifier
{
public:

    float depth;

    Perspective();

    void apply(Note3D& note, float songPosition) override;
};
