#pragma once

#include <string>
#include <unordered_map>

class ShaderManager
{

public:

    ShaderManager();

    bool LoadShader(
        const std::string& name,
        const std::string& vertex,
        const std::string& fragment
    );

    bool UseShader(
        const std::string& name
    );

    void RemoveShader(
        const std::string& name
    );

    void Clear();

private:

    std::unordered_map<std::string,int> shaders;

};
