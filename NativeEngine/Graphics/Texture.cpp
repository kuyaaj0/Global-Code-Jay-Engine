#include "Texture.hpp"

Texture::Texture()
{
    id = 0;
    width = 0;
    height = 0;
    frameWidth = 0;
    frameHeight = 0;
}

bool Texture::Load(
const std::string& path)
{
    // Future:
    // Load PNG/JPG

    id = 1;

    this->path = path;

    return true;
}

const std::string& Texture::GetPath() const
{
    return path;
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

void Texture::SetFrameSize(
int width,
int height)
{
    frameWidth = width;
    frameHeight = height;
}

int Texture::GetFrameWidth() const
{
    return frameWidth;
}

int Texture::GetFrameHeight() const
{
    return frameHeight;
}

int Texture::GetColumns() const
{
    if(frameWidth == 0)
        return 0;

    return width / frameWidth;
}

int Texture::GetRows() const
{
    if(frameHeight == 0)
        return 0;

    return height / frameHeight;
}
