#include "Sudden.hpp"

Sudden::Sudden()
{
    percent = 0.0f;
    appearDistance = 180.0f;
}

void Sudden::apply(Note3D& note, float songPosition)
{
    float distance = note.transform.position.y;

    if (distance > appearDistance)
    {
        note.visible = false;
    }
    else
    {
        note.visible = true;
    }
}
