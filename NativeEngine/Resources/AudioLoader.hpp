#pragma once

#include <string>

class AudioLoader
{

public:

    AudioLoader();

    bool Load(
        const std::string& path
    );

};
