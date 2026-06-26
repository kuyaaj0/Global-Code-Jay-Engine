#include "Stage.hpp"

#include "../../Renderer/Renderer.hpp"

Stage::Stage()
{
    cameraZoom = 1.0f;

    visible = true;
}

void Stage::Load()
{
    // TODO:
    // Load background
    // Load props
    // Load foreground
}

void Stage::Update(float dt)
{

}

void Stage::Render(Renderer* renderer)
{
    // TODO:
    // Render stage objects
}
