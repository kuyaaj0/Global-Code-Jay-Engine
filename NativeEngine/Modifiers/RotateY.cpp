#include "RotateY.hpp"

RotateY::RotateY()
{
    angle = 0.0f;
}

void RotateY::apply(Note3D& note, float songPosition)
{
    note.transform.rotation.y += angle;
}
