#include "Stage.hpp"

#include "../../Renderer/Renderer.hpp"

Stage::Stage()
{
    cameraZoom = 1.0f;

    visible = true;
}

void Stage::Load(const StageData& data)
{
    stageData = data;

    cameraZoom = data.defaultCameraZoom;

    // Future:
    // Load background texture
    // Load foreground texture
    // Load props
}

void Stage::Update(float dt)
{

}

void Stage::Render(Renderer* renderer)
{
    // TODO:
    // Render stage objects
}
