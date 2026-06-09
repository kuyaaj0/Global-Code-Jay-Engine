#include "Mini.hpp"

Mini::Mini()
{
    percent = 0.0f;
    minimumScale = 0.5f;
}

void Mini::apply(Note3D& note, float songPosition)
{
    float scale = 1.0f - (percent * (1.0f - minimumScale));

    note.transform.scale.x *= scale;
    note.transform.scale.y *= scale;
    note.transform.scale.z *= scale;
}
