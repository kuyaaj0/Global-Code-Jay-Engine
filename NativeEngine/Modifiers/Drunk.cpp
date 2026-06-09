#include "Drunk.hpp"
#include <cmath>

Drunk::Drunk()
{
    percent = 0.0f;
    speed = 1.0f;
    spacing = 120.0f;
}

void Drunk::apply(Note3D& note, float songPosition)
{
    note.transform.position.x +=
        std::sin(
            (songPosition / spacing) +
            (note.lane * 0.5f)
        ) * percent * 64.0f;
}
