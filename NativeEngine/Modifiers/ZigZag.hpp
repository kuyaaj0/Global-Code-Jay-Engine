#pragma once

#include "Modifier.hpp"

class ZigZag : public Modifier
{
public:

    float percent;
    float amplitude;
    float speed;

    ZigZag();

    void apply(Note3D& note, float songPosition) override;
};
