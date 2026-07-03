#pragma once

#include <string>

#include "../Gameplay/NoteSkinData.hpp"

class NoteSkinLoader
{
public:

    NoteSkinLoader();

    bool Load(
        const std::string& jsonFile,
        NoteSkinData& data
    );

};
