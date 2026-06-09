#pragma once

#include "Modifier.hpp"

class Beat : public Modifier
{
public:

    float percent;
    float amplitude;
    float speed;

    Beat();

    void apply(Note3D& note, float songPosition) override;
};
