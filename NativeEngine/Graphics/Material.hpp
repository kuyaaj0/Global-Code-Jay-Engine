#pragma once

#include <string>

class Texture;
class ShaderProgram;

class Material
{

public:

    Material();

    void SetTexture(
        Texture* tex
    );

    void SetShader(
        ShaderProgram* shader
    );

    Texture* GetTexture() const;

    ShaderProgram* GetShader() const;

private:

    Texture* texture;

    ShaderProgram* program;

};
