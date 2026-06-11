#include "Note3D.hpp"
#include "../Renderer/Renderer.hpp"

Note3D::Note3D()
{
    Reset();
}

void Note3D::Reset()
{
    transform.Reset();

    velocity = Vector3(0,0,0);

    acceleration = Vector3(0,0,0);

    alpha = 1.0f;

    angle = 0.0f;

    width = 64.0f;

    height = 64.0f;

    scale = 1.0f;

    strumTime = 0.0f;

    visible = true;

    alive = true;

    sustain = false;

    mustPress = false;

    lane = 0;

    noteData = 0;

    player = 0;
}

void Note3D::Update(
float dt)
{
    velocity =
        velocity +
        acceleration * dt;

    transform.Translate(
        velocity * dt
    );
}

void Note3D::Render(
Renderer& renderer)
{
    if(!visible)
        return;

    if(!alive)
        return;

    // Rendering implementation
    // will be connected to Renderer later
}

void Note3D::Kill()
{
    alive = false;
}

void Note3D::Revive()
{
    alive = true;
}
