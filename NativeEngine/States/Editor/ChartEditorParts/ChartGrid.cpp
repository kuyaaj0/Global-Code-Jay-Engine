#include "ChartGrid.hpp"

#include "../../../Renderer/Renderer.hpp"

ChartGrid::ChartGrid()
{
    laneCount = 4;

    laneWidth = 120.0f;

    beatSpacing = 64.0f;
}

void ChartGrid::Update()
{

}

void ChartGrid::Render(
Renderer* renderer)
{
    if(renderer == nullptr)
        return;

    // Future:
    // Draw lane lines
    // Draw beat lines
    // Draw section lines
    // Draw receptors
}
