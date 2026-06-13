#include "Conductor.hpp"

Conductor::Conductor()
{
    bpm = 120.0f;

    songPosition = 0.0f;
}

void Conductor::SetBPM(
float value)
{
    bpm = value;
}

void Conductor::SetSongPosition(
float position)
{
    songPosition = position;
}

void Conductor::Update(
float deltaTime)
{
    songPosition += deltaTime;
}

float Conductor::GetSongPosition() const
{
    return songPosition;
}

float Conductor::GetBeat() const
{
    return
        songPosition /
        (60000.0f / bpm);
}

float Conductor::GetStep() const
{
    return GetBeat() * 4.0f;
}
