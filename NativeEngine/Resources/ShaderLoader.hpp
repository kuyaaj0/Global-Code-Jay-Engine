#pragma once

#include <string>

class ShaderProgram;

class ShaderLoader
{

public:

    ShaderLoader();

    bool Load(
        const std::string& vertexPath,
        const std::string& fragmentPath,
        ShaderProgram& shader
    );

};
