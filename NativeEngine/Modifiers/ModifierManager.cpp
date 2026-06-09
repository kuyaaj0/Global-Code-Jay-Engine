#include "ModifierManager.hpp"

ModifierManager::ModifierManager()
{
   // ModifierManager manager;

manager.addModifier(new Reverse());
manager.addModifier(new Drunk());
manager.addModifier(new Tipsy());
manager.addModifier(new Beat());
manager.addModifier(new Confusion());

manager.addModifier(new Tornado());
manager.addModifier(new ZigZag());
manager.addModifier(new Bounce());

manager.addModifier(new Mini());
manager.addModifier(new Hidden());
manager.addModifier(new Sudden());

manager.addModifier(new Boost());
manager.addModifier(new Brake());
manager.addModifier(new Wave());
manager.addModifier(new Flip());
manager.addModifier(new Invert());

manager.addModifier(new XMod());
manager.addModifier(new CMod());
manager.addModifier(new MMod());

manager.addModifier(new Perspective());

manager.addModifier(new RotateX());
manager.addModifier(new RotateY());
manager.addModifier(new RotateZ());
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
