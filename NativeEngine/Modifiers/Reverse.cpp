#include "Reverse.hpp"

Reverse::Reverse()
{
    percent = 1.0f;
}

void Reverse::apply(Note3D& note, float songPosition)
{
    note.transform.position.y *= -percent;
}
