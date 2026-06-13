#pragma once

#include "../Math/Vector3.hpp"

class ModifierManager;

class Note3D
{

public:

    Note3D();

    void SetLane(int lane);
    void SetTime(float time);

    void Update(
        float songPosition,
        ModifierManager* modifiers
    );

    void Render();

private:

    int lane;

    float noteTime;
    bool hit;

    Vector3 position;

};
