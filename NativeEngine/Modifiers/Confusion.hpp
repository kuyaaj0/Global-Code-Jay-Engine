#pragma once

#include "Modifier.hpp"

class Confusion : public Modifier
{
public:

    float percent;
    float speed;

    Confusion();

    void apply(Note3D& note, float songPosition) override;
};
