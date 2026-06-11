#include "ShaderManager.hpp"

ShaderManager::ShaderManager()
{

}

bool ShaderManager::LoadShader(
const std::string& name,
const std::string& vertex,
const std::string& fragment)
{
    // Future:
    // Compile GLSL

    shaders[name] = 1;

    return true;
}

bool ShaderManager::UseShader(
const std::string& name)
{
    return shaders.find(name)
        != shaders.end();
}

void ShaderManager::RemoveShader(
const std::string& name)
{
    shaders.erase(name);
}

void ShaderManager::Clear()
{
    shaders.clear();
}
