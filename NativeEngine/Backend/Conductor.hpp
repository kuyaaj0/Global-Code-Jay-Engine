#pragma once

class Conductor
{

public:

    float bpm;

    float crochet;

    float stepCrochet;

    float songPosition;

    int curBeat;

    int curStep;

    Conductor();

    void SetBPM(float value);

    void Update(float milliseconds);

};
