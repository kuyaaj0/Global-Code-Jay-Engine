#include "Note3D.hpp"

#include "../Modifier/ModifierManager.hpp"

Note3D::Note3D()
{
    lane = 0;

    noteTime = 0.0f;

    width = 64.0f;
    height = 64.0f;

    hit = false;
    missed = false;

    isHold = false;
    sustainLength = 0.0f;
    
    holding = false;
    completed = false;

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

float Note3D::GetWidth() const
{
    return width;
}

float Note3D::GetHeight() const
{
    return height;
}

bool Note3D::IsHit() const
{
    return hit;
}

void Note3D::SetMissed(bool value)
{
    missed = value;
}

bool Note3D::IsMissed() const
{
    return missed;
}

void Note3D::SetHold(bool value)
{
    isHold = value;
}

void Note3D::SetSustainLength(float value)
{
    sustainLength = value;
}

void Note3D::SetHolding(bool value)
{
    holding = value;
}

bool Note3D::IsHold() const
{
    return isHold;
}

float Note3D::GetSustainLength() const
{
    return sustainLength;
}

bool Note3D::IsHolding() const
{
    return holding;
}

void Note3D::SetCompleted(bool value)
{
    completed = value;
}

bool Note3D::IsCompleted() const
{
    return completed;
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

    if(isHold)
{
    // Visual idea: stretch note downward
    // (later renderer will use sustainLength)
}

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

void Note3D::Render(
Renderer* renderer)
{
    if(renderer == nullptr)
        return;

    // Future:
    // build quad + draw note here
}
