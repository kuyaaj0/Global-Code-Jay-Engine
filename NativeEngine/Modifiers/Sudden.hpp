#pragma once

#include "Modifier.hpp"

class Sudden : public Modifier
{
public:

    float percent;
    float appearDistance;

    Sudden();

    void apply(Note3D& note, float songPosition) override;
};
