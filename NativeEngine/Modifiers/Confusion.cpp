#include "Confusion.hpp"

Confusion::Confusion()
{
    percent = 0.0f;
    speed = 1.0f;
}

void Confusion::apply(Note3D& note, float songPosition)
{
    note.transform.rotation.z +=
        songPosition * speed * percent * 0.05f;
  }
