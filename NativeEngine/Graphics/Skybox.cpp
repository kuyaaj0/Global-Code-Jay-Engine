#include "Skybox.hpp"

Skybox::Skybox()
{
    textureID = 0;
}

bool Skybox::Load(
const std::string& folder)
{
    // Future:
    // Load six cube-map textures

    textureID = 1;

    return true;
}

void Skybox::Draw()
{
    // Future:
    // Draw skybox cube
}

void Skybox::Unload()
{
    textureID = 0;
}
