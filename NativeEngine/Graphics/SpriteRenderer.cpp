#include "SpriteRenderer.hpp"

#include "../Renderer/Renderer.hpp"

SpriteRenderer::SpriteRenderer()
{

}

void SpriteRenderer::Draw(
Renderer* renderer,
Texture* texture,
const AtlasFrame& frame,
const Matrix4& world)
{
    if(renderer == nullptr)
        return;

    if(texture == nullptr)
        return;

    if(texture->GetID() == 0)
        return;

    // TODO:
    // Convert AtlasFrame into UV coordinates.
    // Build the quad.
    // Send it to Renderer.
}
