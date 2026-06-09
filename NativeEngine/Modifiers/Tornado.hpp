#pragma once

#include "Modifier.hpp"

class Tornado : public Modifier
{
public:

    float percent;
    float radius;
    float speed;

    Tornado();

    void apply(Note3D& note, float songPosition) override;
};
