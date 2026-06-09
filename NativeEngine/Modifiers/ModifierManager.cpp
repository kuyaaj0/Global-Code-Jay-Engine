#include "ModifierManager.hpp"

ModifierManager::ModifierManager()
{
}

void ModifierManager::addModifier(
    Modifier* modifier
)
{
    modifiers.push_back(modifier);
}

void ModifierManager::applyModifiers(
    Note3D& note,
    float songPosition
)
{
    for(auto modifier : modifiers)
    {
        modifier->apply(
            note,
            songPosition
        );
    }
}
