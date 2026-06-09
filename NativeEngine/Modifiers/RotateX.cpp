#include "RotateX.hpp"

RotateX::RotateX()
{
    angle = 0.0f;
}

void RotateX::apply(Note3D& note, float songPosition)
{
    note.transform.rotation.x += angle;
}
