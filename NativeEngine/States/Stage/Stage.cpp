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

    background.texture = new Texture();
    background.texture->Load(data.background);

    foreground.texture = new Texture();
    foreground.texture->Load(data.foreground);

    props.texture = new Texture();
    props.texture->Load(data.props);
}

void Stage::Update(float dt)
{

}

void Stage::Render(Renderer* renderer)
{
    background.Draw(renderer);

    foreground.Draw(renderer);

    props.Draw(renderer);
}
