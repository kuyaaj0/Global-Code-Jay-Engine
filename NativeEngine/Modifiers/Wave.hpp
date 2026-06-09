#pragma once

#include "Modifier.hpp"

class Wave : public Modifier
{
public:

    float percent;
    float amplitude;
    float speed;

    Wave();

    void apply(Note3D& note, float songPosition) override;
};
