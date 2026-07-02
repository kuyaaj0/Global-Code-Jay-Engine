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

    void SetFrameSize(
    int width,
    int height
);

    int GetFrameWidth() const;

    int GetFrameHeight() const;

    int GetColumns() const;

    int GetRows() const;

private:

    unsigned int id;

    std::string path;

    int width;

    int height;

    int frameWidth;
    int frameHeight;

};
