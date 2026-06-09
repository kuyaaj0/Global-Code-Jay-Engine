#include "XMod.hpp"

XMod::XMod()
{
    multiplier = 1.0f;
}

void XMod::apply(Note3D& note, float songPosition)
{
    note.transform.position.y *= multiplier;
}
