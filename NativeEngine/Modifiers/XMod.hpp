#pragma once

#include "Modifier.hpp"

class XMod : public Modifier
{
public:

    float multiplier;

    XMod();

    void apply(Note3D& note, float songPosition) override;
};
