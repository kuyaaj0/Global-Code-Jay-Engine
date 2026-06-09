#include "SongPosition.hpp"

SongPosition::SongPosition()
{
    position = 0.0f;
    playbackRate = 1.0f;
    playing = false;
}

void SongPosition::update(float elapsed)
{
    if (playing)
    {
        position += elapsed * playbackRate;
    }
}

void SongPosition::reset()
{
    position = 0.0f;
}
