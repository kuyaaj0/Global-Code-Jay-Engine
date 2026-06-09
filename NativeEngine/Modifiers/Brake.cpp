#include "Brake.hpp"

Brake::Brake()
{
    percent = 0.0f;
    multiplier = 0.5f;
}

void Brake::apply(Note3D& note, float songPosition)
{
    note.transform.position.y -=
        songPosition * percent * multiplier;
}
