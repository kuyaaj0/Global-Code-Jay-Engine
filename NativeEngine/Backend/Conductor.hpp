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

    void Update(
        float deltaTime
    );

    float GetSongPosition() const;

    float GetBeat() const;

    float GetStep() const;

private:

    float bpm;

    float songPosition;

};
