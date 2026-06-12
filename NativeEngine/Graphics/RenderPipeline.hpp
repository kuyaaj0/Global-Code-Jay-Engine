#pragma once

class RenderPipeline
{

public:

    RenderPipeline();

    void BeginFrame();

    void GeometryPass();

    void LightingPass();

    void PostProcessPass();

    void EndFrame();

};
