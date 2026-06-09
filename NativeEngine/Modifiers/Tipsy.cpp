#include "Tipsy.hpp"
#include <cmath>

Tipsy::Tipsy()
{
    percent = 0.0f;
}

void Tipsy::apply(Note3D& note, float songPosition)
{
    note.transform.position.y +=
        std::sin(
            songPosition * 0.01f +
            note.lane
        ) * percent * 32.0f;
}
