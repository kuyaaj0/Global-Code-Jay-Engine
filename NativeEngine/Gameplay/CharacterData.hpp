#pragma once

#include <string>

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

    Vector3 GetCameraFocus() const;

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
    }

    private:

        CharacterData* characterData;
};
