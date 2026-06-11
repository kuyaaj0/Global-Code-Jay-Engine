#include "ModifierManager.hpp"

#include <cmath>

ModifierManager::ModifierManager()
{
    Reset();
}

void ModifierManager::Reset()
{
    reverse = 0.0f;

    drunk = 0.0f;

    tipsy = 0.0f;

    tornado = 0.0f;

    zigzag = 0.0f;

    bounce = 0.0f;

    mini = 0.0f;

    hidden = 0.0f;

    sudden = 0.0f;

    boost = 0.0f;

    brake = 0.0f;

    wave = 0.0f;

    flip = 0.0f;

    invert = 0.0f;

    xmod = 1.0f;

    cmod = 0.0f;

    mmod = 0.0f;

    perspective = 0.0f;

    rotateX = 0.0f;

    rotateY = 0.0f;

    rotateZ = 0.0f;
}

void ModifierManager::Apply(
Note3D& note,
float songPosition)
{
    // Reverse
    if(reverse != 0.0f)
    {
        note.transform.position.y *= -1.0f;
    }

    // Mini
    if(mini != 0.0f)
    {
        note.scale *=
            (1.0f - 0.5f * mini);
    }

    // Hidden
    if(hidden != 0.0f)
    {
        note.alpha *=
            (1.0f - hidden);
    }

    // Sudden
    if(sudden != 0.0f)
    {
        note.alpha *=
            sudden;
    }

    // Wave
    if(wave != 0.0f)
    {
        note.transform.position.x +=
            std::sin(songPosition * 0.01f)
            * 50.0f
            * wave;
    }

    // Bounce
    if(bounce != 0.0f)
    {
        note.transform.position.y +=
            std::abs(
                std::sin(songPosition * 0.01f)
            )
            * 40.0f
            * bounce;
    }

    // Rotation placeholders
    note.angle += rotateZ;

    // Future:
    // Drunk
    // Tipsy
    // Tornado
    // ZigZag
    // Boost
    // Brake
    // Perspective
    // RotateX
    // RotateY
    // Flip
    // Invert
    // XMod/CMod/MMod
}
