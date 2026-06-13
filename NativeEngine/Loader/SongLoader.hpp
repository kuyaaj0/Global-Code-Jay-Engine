#pragma once

#include <string>

class SongLoader
{

public:

    SongLoader();

    bool Load(
        const std::string& song
    );

    std::string GetSongPath() const;

private:

    std::string currentSong;

};
