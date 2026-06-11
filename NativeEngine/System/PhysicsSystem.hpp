#pragma once

#include "../Math/Vector3.hpp"

class PhysicsSystem
{

public:

    PhysicsSystem();

    void ApplyGravity(
        Vector3& position,
        Vector3& velocity,
        float dt
    );

    void Reset();

private:

    float gravity;

};
