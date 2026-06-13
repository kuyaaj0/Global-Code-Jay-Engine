#include "Note3D.hpp"

Note3D::Note3D()
{
    lane = 0;

    noteTime = 0.0f;

    yPosition = 0.0f;
}

void Note3D::SetLane(
int value)
{
    lane = value;
}

void Note3D::SetTime(
float value)
{
    noteTime = value;
}

void Note3D::Update(
float currentSongPosition)
{
    float distance =
        noteTime -
        currentSongPosition;

    yPosition =
        distance *
        0.45f;
}

void Note3D::Render()
{
    // Future:
    // Draw note at yPosition
}
