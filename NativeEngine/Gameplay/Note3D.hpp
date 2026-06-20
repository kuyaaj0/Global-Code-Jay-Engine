#pragma once

#include "../Math/Vector3.hpp"

class ModifierManager;
class Renderer;

class Note3D
{

public:

    Note3D();

    void SetLane(int lane);

    void SetTime(float time);

    void SetHit(bool value);

    void SetHold(bool value);

    void SetHolding(bool value);
    
    bool IsHold() const;

    void SetSustainLength(
    float value
);

    float GetSustainLength() const;

    int GetLane() const;

    float GetTime() const;

    float GetWidth() const;
    float GetHeight() const;

    bool IsHit() const;

    void SetMissed(bool value);
    bool IsMissed() const;

    void SetCompleted(bool value);
    bool IsHolding() const;
    bool IsCompleted() const;

    const Vector3& GetPosition() const;

    void Update(
        float songPosition,
        ModifierManager* modifiers
    );

    void Render(
    Renderer* renderer
    );

private:

    int lane;

    float noteTime;

    float width;
    float height;

    bool hit;
    bool missed;

    bool isHold;
    float sustainLength;
    bool completed;

    Vector3 position;

};
