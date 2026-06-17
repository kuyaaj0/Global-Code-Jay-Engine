#include "AudioManager.hpp"

AudioManager::AudioManager()
{
    currentPosition = 0.0f;

    playing = false;
}

bool AudioManager::LoadSong(
const std::string& path)
{
    // Future:
    // Decode OGG
    // Decode MP3
    // Decode WAV

    currentPosition = 0.0f;

    return true;
}

void AudioManager::Play()
{
    playing = true;
}

void AudioManager::Pause()
{
    playing = false;
}

void AudioManager::Stop()
{
    playing = false;

    currentPosition = 0.0f;
}

void AudioManager::Seek(
float milliseconds)
{
    currentPosition =
        milliseconds;
}

float AudioManager::GetPlaybackPosition() const
{
    return playbackPosition;;
}

bool AudioManager::IsPlaying() const
{
    return playing;
}
