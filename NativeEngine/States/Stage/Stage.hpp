#pragma once

#include "../../Transform/Transform.hpp"

class Renderer;

class Stage
{

public:

    Transform transform;

    float cameraZoom;

    bool visible;

    Stage();

    void Load(
    const StageData& data
);

    void Update(float dt);

    void Render(Renderer* renderer);

};
