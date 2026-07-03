#pragma once

#include <string>
#include "../Math/Vector3.hpp"

struct CharacterData
{
    // Basic Info
    std::string name;
    std::string displayName;
    std::string folder;

    // Graphics
    std::string spriteAtlas;
    std::string spriteXML;
    std::string spriteJSON;
    std::string animationFile;
    std::string icon;

    // Character Configuration
    std::string offsets;
    std::string healthColor;

    // Gameplay
    bool playerCharacter;
    bool flipX;
    bool flipY;

    // Camera
    Vector3 cameraOffset;

    // Default Constructor
    CharacterData()
    {
        name = "";
        displayName = "";
        folder = "";

        spriteAtlas = "";
        spriteXML = "";
        spriteJSON = "";
        animationFile = "";
        icon = "";

        offsets = "";
        healthColor = "#FFFFFF";

        playerCharacter = false;

        flipX = false;
        flipY = false;

        cameraOffset = Vector3(0.0f, 0.0f, 0.0f);
    }
};
