#include "PlayField.hpp"

PlayField::PlayField()
{
    Reset();
}

void PlayField::Reset()
{
    position = Vector3(0.0f,0.0f,0.0f);

    laneWidth = 112.0f;

    receptorY = 100.0f;

    scrollSpeed = 1.0f;

    downscroll = false;

    middlescroll = false;

    keyCount = 4;
}

float PlayField::GetLaneX(
int lane) const
{
    return position.x +
           laneWidth * lane;
}

void PlayField::Update(
float dt)
{
    // Future:
    // Camera effects
    // Playfield movement
    // Dynamic lane spacing
}
