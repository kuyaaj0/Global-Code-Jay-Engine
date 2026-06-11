#include "ReplayManager.hpp"

ReplayManager::ReplayManager()
{
    recording = false;
    playing = false;
}

void ReplayManager::StartRecording()
{
    replay.clear();
    recording = true;
}

void ReplayManager::StopRecording()
{
    recording = false;
}

void ReplayManager::StartPlayback()
{
    playing = true;
}

void ReplayManager::StopPlayback()
{
    playing = false;
}

void ReplayManager::AddFrame(
const ReplayFrame& frame)
{
    if(recording)
        replay.push_back(frame);
}

void ReplayManager::Clear()
{
    replay.clear();
}

bool ReplayManager::IsRecording() const
{
    return recording;
}

bool ReplayManager::IsPlaying() const
{
    return playing;
}
