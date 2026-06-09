#include "Flip.hpp"

Flip::Flip()
{
    percent = 0.0f;
}

void Flip::apply(Note3D& note, float songPosition)
{
    note.transform.position.x *= -1.0f * percent;
}
