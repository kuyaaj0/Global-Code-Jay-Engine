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

    int GetLane() const;

    float GetTime() const;

    float GetWidth() const;
    float GetHeight() const;

    bool IsHit() const;

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

    Vector3 position;

};
