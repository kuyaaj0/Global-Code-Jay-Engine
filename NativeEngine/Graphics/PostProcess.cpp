#include "PostProcess.hpp"

PostProcess::PostProcess()
{
    enabled = false;
}

bool PostProcess::LoadShader(
const std::string& name)
{
    // Future:
    // Load post-processing shader

    return true;
}

void PostProcess::Enable()
{
    enabled = true;
}

void PostProcess::Disable()
{
    enabled = false;
}

bool PostProcess::IsEnabled() const
{
    return enabled;
}
