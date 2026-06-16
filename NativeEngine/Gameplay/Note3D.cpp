#include "Note3D.hpp"

#include "../Modifier/ModifierManager.hpp"

Note3D::Note3D()
{
    lane = 0;

    noteTime = 0.0f;

    width = 64.0f;
    height = 64.0f;

    hit = false;

    position = Vector3();
}

void Note3D::SetLane(int value)
{
    lane = value;
}

void Note3D::SetTime(float value)
{
    noteTime = value;
}

void Note3D::SetHit(bool value)
{
    hit = value;
}

int Note3D::GetLane() const
{
    return lane;
}

float Note3D::GetTime() const
{
    return noteTime;
}

bool Note3D::IsHit() const
{
    return hit;
}

const Vector3& Note3D::GetPosition() const
{
    return position;
}

void Note3D::Update(
float songPosition,
ModifierManager* modifiers)
{
    float distance =
        noteTime -
        songPosition;

    position.x =
        lane * 120.0f;

    position.y =
        distance * 0.45f;

    position.z = 0.0f;

    if(modifiers != nullptr)
    {
        position =
            modifiers->Apply(
                lane,
                distance,
                position
            );
    }
}

void Note3D::Render()
{
    // Future:
    // Renderer->Draw(position)
}
