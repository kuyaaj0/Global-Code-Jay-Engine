#pragma once

#include <string>

class FontLoader
{

public:

    FontLoader();

    bool Load(
        const std::string& path
    );

};
