#pragma once

class Matrix4Render
{
public:

    static void initialize();

    static void shutdown();

    static void update(float deltaTime);

    static void beginFrame();

    static void endFrame();

    static bool isInitialized();
};
