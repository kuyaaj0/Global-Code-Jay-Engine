#pragma once

#include <string>

struct AtlasFrame
{
    std::string name;

    int x;
    int y;

    int width;
    int height;

    int frameX;
    int frameY;

    int frameWidth;
    int frameHeight;

    AtlasFrame()
    {
        name = "";

        x = 0;
        y = 0;

        width = 0;
        height = 0;

        frameX = 0;
        frameY = 0;

        frameWidth = 0;
        frameHeight = 0;
    }
};
