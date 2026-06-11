#include "Texture.hpp"

Texture::Texture()
{
    id = 0;
    width = 0;
    height = 0;
}

bool Texture::Load(
const std::string& path)
{
    // Future:
    // Load PNG/JPG

    id = 1;

    return true;
}

void Texture::Unload()
{
    id = 0;
}

int Texture::GetWidth() const
{
    return width;
}

int Texture::GetHeight() const
{
    return height;
}
