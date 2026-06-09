#include "StrumLine3D.hpp"

StrumLine3D::StrumLine3D()
{
    position = Vector3(0.0f, 0.0f, 0.0f);
    rotation = Vector3(0.0f, 0.0f, 0.0f);
    scale = Vector3(1.0f, 1.0f, 1.0f);

    laneCount = 4;
}

Vector3 StrumLine3D::getLanePosition(int lane)
{
    float spacing = 112.0f;

    return Vector3(
        position.x + (lane * spacing),
        position.y,
        position.z
    );
}
