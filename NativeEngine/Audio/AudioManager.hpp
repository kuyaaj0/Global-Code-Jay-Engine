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

    float GetPosition() const;

    bool IsPlaying() const;

private:

    float currentPosition;

    bool playing;

};
