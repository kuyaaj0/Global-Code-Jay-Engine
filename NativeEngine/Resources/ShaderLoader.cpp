#include "ShaderLoader.hpp"
#include "../Graphics/ShaderProgram.hpp"

ShaderLoader::ShaderLoader()
{

}

bool ShaderLoader::Load(
const std::string& vertexPath,
const std::string& fragmentPath,
ShaderProgram& shader)
{
    return shader.Compile(
        vertexPath,
        fragmentPath
    );
}
