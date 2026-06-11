#pragma once

#include "../Core/Transform.hpp"

class Renderer;

class StrumLine
{

public:

    Transform transform;

    int lane;

    int player;

    bool pressed;

    bool confirm;

    bool staticState;

    float alpha;

    float angle;

    StrumLine();

    void Reset();

    void Update(
        float dt
    );

    void Render(
        Renderer& renderer
    );

};
