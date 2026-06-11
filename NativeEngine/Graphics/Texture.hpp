#pragma once

#include <string>

class Texture
{

public:

    Texture();

    bool Load(
        const std::string& path
    );

    void Unload();

    int GetWidth() const;

    int GetHeight() const;

private:

    unsigned int id;

    int width;

    int height;

};
