#include "Tornado.hpp"
#include <cmath>

Tornado::Tornado()
{
    percent = 0.0f;
    radius = 64.0f;
    speed = 1.0f;
}

void Tornado::apply(Note3D& note, float songPosition)
{
    float angle =
        (songPosition * 0.01f * speed) +
        (note.lane * 0.8f);

    note.transform.position.x +=
        std::sin(angle) * radius * percent;

    note.transform.position.z +=
        std::cos(angle) * radius * percent;
}
