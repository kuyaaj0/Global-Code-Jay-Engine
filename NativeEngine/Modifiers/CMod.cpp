#include "CMod.hpp"

CMod::CMod()
{
    speed = 400.0f;
}

void CMod::apply(Note3D& note, float songPosition)
{
    note.transform.position.y =

        note.strumTime - songPosition;

    note.transform.position.y *= speed;
}
