#pragma once

class Conductor
{

public:

    Conductor();

    void SetBPM(
        float bpm
    );

    void SetSongPosition(
        float position
    );

    bool IsBeatHit() const;

    bool IsStepHit() const;

    int GetCurrentBeat() const;

    int GetCurrentStep() const;

    void Update(
        float deltaTime
    );

    float GetSongPosition() const;

    float GetBeat() const;

    float GetStep() const;

private:

    float bpm;

    float songPosition;

    int currentBeat;

    int currentStep;

    bool beatHit;

    bool stepHit;

};
