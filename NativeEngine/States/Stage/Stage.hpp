#pragma once

#include "../../Transform/Transform.hpp"
#include "../../Gameplay/StageData.hpp"
#include "../../Graphics/Sprite.hpp"
#include "../../Graphics/Texture.hpp"

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

private:

    Sprite background;

    Sprite foreground;

    Sprite props;

    StageData stageData;

};
