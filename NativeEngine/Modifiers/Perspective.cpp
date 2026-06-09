#include "Perspective.hpp"

Perspective::Perspective()
{
    depth = 500.0f;
}

void Perspective::apply(Note3D& note, float songPosition)
{
    float factor =

        depth /

        (depth + note.transform.position.z);

    note.transform.position.x *= factor;

    note.transform.position.y *= factor;
}
