#pragma once

class Renderer;

class ChartGrid
{

public:

    ChartGrid();

    void Update();

    void Render(
        Renderer* renderer
    );

private:

    int laneCount;

    float laneWidth;

    float beatSpacing;

    int visibleBeats;

};
