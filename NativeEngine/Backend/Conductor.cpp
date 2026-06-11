#include "Conductor.hpp"

Conductor::Conductor()
{
    bpm = 120.0f;

    songPosition = 0.0f;

    curBeat = 0;

    curStep = 0;

    SetBPM(bpm);
}

void Conductor::SetBPM(float value)
{
    bpm = value;

    crochet = 60000.0f / bpm;

    stepCrochet = crochet / 4.0f;
}

void Conductor::Update(float milliseconds)
{
    songPosition = milliseconds;

    curBeat =
        (int)(songPosition / crochet);

    curStep =
        (int)(songPosition / stepCrochet);
}
