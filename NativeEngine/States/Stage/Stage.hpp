#pragma once

#include "../../Transform/Transform.hpp"

class Stage
{

public:

    Transform transform;

    float cameraZoom;

    bool visible;

    Stage();

    void Load();

    void Update(float dt);

    void Render();

};
