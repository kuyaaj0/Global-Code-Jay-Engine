#pragma once

#include <vector>
#include "Modifier.hpp"

class ModifierManager
{
public:

    std::vector<Modifier*> modifiers;

    ModifierManager();

    void addModifier(
        Modifier* modifier
    );

    void applyModifiers(
        Note3D& note,
        float songPosition
    );
};
