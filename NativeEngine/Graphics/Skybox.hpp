#pragma once

#include <string>

class Skybox
{

public:

    Skybox();

    bool Load(
        const std::string& folder
    );

    void Draw();

    void Unload();

private:

    unsigned int textureID;

};
