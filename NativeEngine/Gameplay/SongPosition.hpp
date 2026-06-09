#pragma once

class SongPosition
{
public:

    // Current song position in milliseconds
    float position;

    // Playback speed
    float playbackRate;

    // Is the song currently playing?
    bool playing;

    SongPosition();

    void update(float elapsed);

    void reset();
};
