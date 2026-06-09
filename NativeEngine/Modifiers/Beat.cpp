#include "Beat.hpp"
#include <cmath>

Beat::Beat()
{
    percent = 0.0f;
    amplitude = 24.0f;
    speed = 1.0f;
}

void Beat::apply(Note3D& note, float songPosition)
{
    float beat =
        std::sin(songPosition * 0.01f * speed);

    note.transform.position.y +=
        beat * amplitude * percent;
}
