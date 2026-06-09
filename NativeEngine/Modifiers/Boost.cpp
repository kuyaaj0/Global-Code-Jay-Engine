#include "Boost.hpp"

Boost::Boost()
{
    percent = 0.0f;
    multiplier = 2.0f;
}

void Boost::apply(Note3D& note, float songPosition)
{
    note.transform.position.y -=
        songPosition * percent * multiplier;
}
