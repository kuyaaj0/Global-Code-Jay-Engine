#include "Bounce.hpp"
#include <cmath>

Bounce::Bounce()
{
    percent = 0.0f;
    amplitude = 32.0f;
    speed = 1.0f;
}

void Bounce::apply(Note3D& note, float songPosition)
{
    float bounce =
        std::fabs(
            std::sin(songPosition * 0.01f * speed)
        );

    note.transform.position.y +=
        bounce * amplitude * percent;
}
