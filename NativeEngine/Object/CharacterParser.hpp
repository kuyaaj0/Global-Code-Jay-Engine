#pragma once

#include <string>

#include "../Gameplay/CharacterData.hpp"

class CharacterParser
{
public:

    CharacterParser();

    bool Parse(
        const std::string& folder,
        CharacterData& data
    );

};
