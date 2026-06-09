#include "Invert.hpp"

Invert::Invert()
{
    percent = 0.0f;
}

void Invert::apply(Note3D& note, float songPosition)
{
    if (note.lane == 0)
        note.transform.position.x += 3 * percent;

    else if (note.lane == 1)
        note.transform.position.x += 1 * percent;

    else if (note.lane == 2)
        note.transform.position.x -= 1 * percent;

    else if (note.lane == 3)
        note.transform.position.x -= 3 * percent;
}
