#include "Material.hpp"

Material::Material()
{
    texture = nullptr;
    program = nullptr;
}

void Material::SetTexture(
Texture* tex)
{
    texture = tex;
}

void Material::SetShader(
ShaderProgram* shader)
{
    program = shader;
}

Texture* Material::GetTexture() const
{
    return texture;
}

ShaderProgram* Material::GetShader() const
{
    return program;
}
