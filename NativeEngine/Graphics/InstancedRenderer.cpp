#include "InstancedRenderer.hpp"
#include "Model.hpp"

InstancedRenderer::InstancedRenderer()
{

}

void InstancedRenderer::AddInstance(
Model* model)
{
    if(model != nullptr)
    {
        instances.push_back(model);
    }
}

void InstancedRenderer::Render()
{
    for(auto model : instances)
    {
        if(model != nullptr)
        {
            // Future:
            // GPU instanced draw
        }
    }
}

void InstancedRenderer::Clear()
{
    instances.clear();
}
