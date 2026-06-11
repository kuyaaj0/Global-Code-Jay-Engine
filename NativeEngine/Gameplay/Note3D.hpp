#pragma once

#include "../Transform/Transform.hpp"
#include "../Math/Vector3.hpp"

class Renderer;

class Note3D
{

public:

    Transform transform;

    Vector3 velocity;

    Vector3 acceleration;

    float alpha;

    float angle;

    float width;

    float height;

    float scale;

    float strumTime;

    bool visible;

    bool alive;

    bool sustain;

    bool mustPress;

    int lane;

    int noteData;

    int player;

    Note3D();

    void Update(
        float dt
    );

    void Render(
        Renderer& renderer
    );

    void Reset();

    void Kill();

    void Revive();

};
