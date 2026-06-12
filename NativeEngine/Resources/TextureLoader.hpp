Texture texture;
#pragma once

#include <string>

class Texture;

class TextureLoader
{

public:

    TextureLoader();

    bool Load(
        const std::string& path,
        Texture& texture
    );

};;
