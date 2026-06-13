#pragma once

#include "../Math/Vector3.hpp"

class ModifierManager
{

public:

    ModifierManager();

    void SetReverse(float value);
    void SetBoost(float value);
    void SetBrake(float value);
    void SetWave(float value);
    void SetMini(float value);
    void SetFlip(float value);

    Vector3 Apply(
        int lane,
        float distance,
        const Vector3 position
    );

private:

    float reverse;
    float boost;
    float brake;
    float wave;
    float mini;
    float flip;

};
