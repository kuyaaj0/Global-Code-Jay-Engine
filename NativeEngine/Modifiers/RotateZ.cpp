#include "RotateZ.hpp"

RotateZ::RotateZ()
{
    angle = 0.0f;
}

void RotateZ::apply(Note3D& note, float songPosition)
{
    note.transform.rotation.z += angle;
}
