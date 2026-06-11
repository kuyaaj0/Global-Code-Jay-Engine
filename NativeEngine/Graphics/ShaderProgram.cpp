#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram()
{
    programID = 0;
}

bool ShaderProgram::Compile(
const std::string& vertexSource,
const std::string& fragmentSource)
{
    // Future:
    // Compile OpenGL/Vulkan shader

    programID = 1;

    return true;
}

void ShaderProgram::Bind()
{

}

void ShaderProgram::Unbind()
{

}

unsigned int ShaderProgram::GetID() const
{
    return programID;
}
