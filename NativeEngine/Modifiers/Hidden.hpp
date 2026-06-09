#pragma once

#include "Modifier.hpp"

class Hidden : public Modifier
{
public:

    float percent;
    float startFade;
    float endFade;

    Hidden();

    void apply(Note3D& note, float songPosition) override;
};
