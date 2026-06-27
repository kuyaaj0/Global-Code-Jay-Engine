#pragma once

#include <string>

#include "../Gameplay/CharacterData.hpp"

class CharacterLoader
{
public:

    CharacterLoader();

    CharacterData LoadCharacter(
        const std::string& characterName
    );

private:

    std::string FindCharacterFolder(
        const std::string& characterName
    );

    bool FolderExists(
        const std::string& path
    );
};
