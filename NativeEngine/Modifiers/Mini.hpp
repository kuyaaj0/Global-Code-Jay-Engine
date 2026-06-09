#pragma once

#include "Modifier.hpp"

class Mini : public Modifier
{
public:

    float percent;
    float minimumScale;

    Mini();

    void apply(Note3D& note, float songPosition) override;
};
