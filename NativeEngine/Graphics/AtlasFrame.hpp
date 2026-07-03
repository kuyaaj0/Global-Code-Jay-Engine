#pragma once

#include <string>

struct AtlasFrame
{
    std::string name;

    int x = 0;
    int y = 0;

    int width = 0;
    int height = 0;

    int frameX = 0;
    int frameY = 0;

    int frameWidth = 0;
    int frameHeight = 0;

    bool rotated = false;
    bool trimmed = false;
};
