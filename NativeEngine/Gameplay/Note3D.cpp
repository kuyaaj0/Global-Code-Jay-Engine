#include "Note3D.hpp"

Note3D::Note3D()
{
    position = Vector3(0.0f, 0.0f, 0.0f);

    rotation = Vector3(0.0f, 0.0f, 0.0f);

    scale = Vector3(1.0f, 1.0f, 1.0f);

    lane = 0;

    visible = true;

    sustain = false;

    strumTime = 0.0f;
}
