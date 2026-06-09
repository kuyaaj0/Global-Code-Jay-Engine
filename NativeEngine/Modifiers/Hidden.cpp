#include "Hidden.hpp"

Hidden::Hidden()
{
    percent = 0.0f;
    startFade = 200.0f;
    endFade = 50.0f;
}

void Hidden::apply(Note3D& note, float songPosition)
{
    float distance = note.transform.position.y;

    if (distance < startFade && distance > endFade)
    {
        note.visible = false;
    }
}
