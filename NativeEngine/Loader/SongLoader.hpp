#pragma once

#include <string>

class SongLoader
{

public:

    bool LoadSong(

        const std::string& folder

    );

    bool LoadChart(

        const std::string& chart

    );

    bool LoadAudio(

        const std::string& audio

    );

};
