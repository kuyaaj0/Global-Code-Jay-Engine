#include "MMod.hpp"

MMod::MMod()
{
    targetSpeed = 600.0f;
}

void MMod::apply(Note3D& note, float songPosition)
{
    note.transform.position.y *=

        targetSpeed / 600.0f;
}
