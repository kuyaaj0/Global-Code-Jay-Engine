#pragma once

#include <string>

class ShaderProgram
{

public:

    ShaderProgram();

    bool Compile(
        const std::string& vertexSource,
        const std::string& fragmentSource
    );

    void Bind();

    void Unbind();

    unsigned int GetID() const;

private:

    unsigned int programID;

};
