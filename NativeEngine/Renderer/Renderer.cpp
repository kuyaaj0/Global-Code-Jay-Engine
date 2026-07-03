#include "Renderer.hpp"
#include "../Graphics/Texture.hpp"
#include "../Graphics/Sprite.hpp"

Renderer::Renderer()
{
    activeCamera = nullptr;
}

void Renderer::SetCamera(
Camera3D* camera)
{
    activeCamera = camera;

    matrixRenderer.SetCamera(camera);
}

void Renderer::BeginFrame()
{
    // Future:
    // Clear render queue
    // Reset statistics
}

void Renderer::EndFrame()
{
    // Future:
    // Flush render queue
    // Present frame
}

void Renderer::Clear()
{
    // Future:
    // Clear color buffer
    // Clear depth buffer
}

void Renderer::DrawVertex(
const Matrix4& world,
const Vector4& vertex)
{
    Vector4 screenVertex =
        matrixRenderer.WorldToScreen(
            world,
            vertex
        );

    // Future:
    // Send screenVertex to GPU
}

void Renderer::DrawQuad(
const Matrix4& world,
const Vector4 vertices[4])
{
    for(int i = 0; i < 4; i++)
    {
        DrawVertex(
            world,
            vertices[i]
        );
    }
}

void Renderer::DrawNote(
Texture* texture,
const AtlasFrame& frame,
const Matrix4& world)
{
    if(texture == nullptr)
        return;

    if(texture->GetID() == 0)
        return;

    // TODO:
    // Build UV coordinates from AtlasFrame
    // Draw the selected frame from the texture atlas
}
