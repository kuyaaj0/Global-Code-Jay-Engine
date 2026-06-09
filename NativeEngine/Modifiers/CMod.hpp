#pragma once

#include "Modifier.hpp"

class CMod : public Modifier
{
public:

    float speed;

    CMod();

    void apply(Note3D& note, float songPosition) override;
};
