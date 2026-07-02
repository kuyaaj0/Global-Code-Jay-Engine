#pragma once

#include <string>

class Texture
{

public:

    Texture();

    bool Load(
        const std::string& path
    );

    const std::string& GetPath() const;

    void Unload();

    int GetWidth() const;

    int GetHeight() const;

private:

    unsigned int id;

    std::string path;

    int width;

    int height;

};
