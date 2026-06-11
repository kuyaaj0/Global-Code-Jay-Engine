#include "RenderTexture.hpp"

RenderTexture::RenderTexture()
{
    framebuffer = nullptr;

    texture = nullptr;
}

bool RenderTexture::Create(
int width,
int height)
{
    // Future:
    // Create framebuffer
    // Attach texture

    return true;
}

void RenderTexture::Begin()
{

}

void RenderTexture::End()
{

}

Texture* RenderTexture::GetTexture()
{
    return texture;
}
