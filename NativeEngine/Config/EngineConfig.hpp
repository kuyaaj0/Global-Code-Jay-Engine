#pragma once

class EngineConfig
{
public:

    // Engine Selection
    static int engine;

    // Gameplay
    static bool downscroll;
    static bool middlescroll;
    static float scrollSpeed;
    static int safeFrames;

    // Performance
    static bool performanceMode;
    static bool lowEndMode;
    static bool matrix4Pipeline;

    // Modcharts
    static bool luaModcharts;
    static bool enable3D;
    static bool perspectiveCamera;
    static bool matrixTransforms;
    static bool optimizeLua;
    static bool notitgEffects;
    static bool depthSorting;
};
