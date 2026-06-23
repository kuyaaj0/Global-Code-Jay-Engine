#pragma once

#include <string>

class AudioManager
{

public:

    AudioManager();

    bool LoadSong(
        const std::string& path
    );

    void Play();

    void Pause();

    void Stop();

    void Seek(
        float milliseconds
    );

    float GetPlaybackPosition() const;

    float GetCurrentPosition() const;

    bool IsPlaying() const;

private:

    float playbackPosition;

    float currentPosition;

    bool playing;

};
