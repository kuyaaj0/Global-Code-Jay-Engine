#pragma once

#include "Modifier.hpp"

class MMod : public Modifier
{
public:

    float targetSpeed;

    MMod();

    void apply(Note3D& note, float songPosition) override;
};
