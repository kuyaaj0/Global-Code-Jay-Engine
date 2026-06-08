#include "Matrix4Render.hpp"

#include <iostream>

static bool g_initialized = false;

void Matrix4Render::initialize()
{
    if(g_initialized)
        return;

    std::cout << "[Matrix4Render] Initializing..." << std::endl;

    g_initialized = true;
}

void Matrix4Render::shutdown()
{
    if(!g_initialized)
        return;

    std::cout << "[Matrix4Renderer] Shutdown." << std::endl;

    g_initialized = false;
}

void Matrix4Render::update(float deltaTime)
{
    if(!g_initialized)
        return;

    // Future Matrix4 calculations here
}

void Matrix4Render::beginFrame()
{
    if(!g_initialized)
        return;

    // Future rendering setup
}

void Matrix4Render::endFrame()
{
    if(!g_initialized)
        return;

    // Future rendering cleanup
}

bool Matrix4Render::isInitialized()
{
    return g_initialized;
}
