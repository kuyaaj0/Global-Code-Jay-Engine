#pragma once

class TimingSystem
{

public:

    TimingSystem();

    void Reset();

    void Update(
        float deltaTime
    );

    float GetDeltaTime() const;

    float GetElapsedTime() const;

private:

    float deltaTime;

    float elapsedTime;

};
