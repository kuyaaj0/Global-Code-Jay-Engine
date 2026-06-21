#include "ChartGrid.hpp"

#include "../../../Renderer/Renderer.hpp"
#include "../../../Math/Matrix4.hpp"
#include "../../../Math/Vector4.hpp"

ChartGrid::ChartGrid()
{
    laneCount = 4;

    laneWidth = 120.0f;

    beatSpacing = 64.0f;

    visibleBeats = 32;
}

void ChartGrid::Update()
{

}

void ChartGrid::Render(
Renderer* renderer)
{
    if(renderer == nullptr)
        return;

    float gridHeight =
        visibleBeats *
        beatSpacing;

    for(int lane = 0;
        lane < laneCount;
        lane++)
    {
        float x =
            (lane - 1.5f) *
            laneWidth;

        Matrix4 world =
            Matrix4::Translation(
                x,
                0.0f,
                0.0f
            ) *
            Matrix4::Scale(
                laneWidth,
                gridHeight,
                1.0f
            );

        Vector4 quad[4];

        quad[0] =
            Vector4(-0.5f,-0.5f,0.0f,1.0f);

        quad[1] =
            Vector4( 0.5f,-0.5f,0.0f,1.0f);

        quad[2] =
            Vector4( 0.5f, 0.5f,0.0f,1.0f);

        quad[3] =
            Vector4(-0.5f, 0.5f,0.0f,1.0f);

        renderer->DrawQuad(
            world,
            quad
        );
    }
}
