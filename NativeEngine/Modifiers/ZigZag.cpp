#include "ZigZag.hpp"
#include <cmath>

ZigZag::ZigZag()
{
    percent = 0.0f;
    amplitude = 48.0f;
    speed = 1.0f;
}

void ZigZag::apply(Note3D& note, float songPosition)
{
    float wave =
        std::asin(
            std::sin(songPosition * 0.01f * speed)
        );

    note.transform.position.x +=
        wave * amplitude * percent;
}
