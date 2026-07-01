#include "Conductor.hpp"

Conductor::Conductor()
{
    bpm = 120.0f;

    songPosition = 0.0f;

    currentBeat = 0;

    currentStep = 0;

    beatHit = false;

    stepHit = false;
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

bool Conductor::IsBeatHit() const
{
    return beatHit;
}

bool Conductor::IsStepHit() const
{
    return stepHit;
}

int Conductor::GetCurrentBeat() const
{
    return currentBeat;
}

int Conductor::GetCurrentStep() const
{
    return currentStep;
}

void Conductor::Update(
float deltaTime)
{
    songPosition += deltaTime;

beatHit = false;
stepHit = false;

int beat = (int)GetBeat();

if(beat > currentBeat)
{
    currentBeat = beat;
    beatHit = true;
}

int step = (int)GetStep();

if(step > currentStep)
{
    currentStep = step;
    stepHit = true;
}
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
