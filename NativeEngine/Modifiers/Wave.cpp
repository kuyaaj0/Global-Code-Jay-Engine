#include "Wave.hpp"
#include <cmath>

Wave::Wave()
{
    percent = 0.0f;
    amplitude = 40.0f;
    speed = 1.0f;
}

void Wave::apply(Note3D& note, float songPosition)
{
    note.transform.position.x +=

        std::sin(

            songPosition * 0.01f * speed

        ) * amplitude * percent;
}
