#pragma once

#include <string>

struct StageData
{
    // Basic Information
    std::string name;
    std::string displayName;
    std::string folder;

    // Stage Assets
    std::string background;
    std::string foreground;
    std::string props;

    // Stage Configuration
    float defaultCameraZoom;

    bool pixelStage;

    // Constructor
    StageData()
    {
        name = "";
        displayName = "";
        folder = "";

        background = "";
        foreground = "";
        props = "";

        defaultCameraZoom = 1.0f;

        pixelStage = false;
    }

   private:

        StageData* stageData;
};
