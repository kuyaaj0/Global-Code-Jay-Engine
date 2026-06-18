#pragma once

#include <string>

class SongMetadata;

class SongLoader
{

public:

    SongLoader();

    bool Load(
        const std::string& song
    );

    std::string GetSongPath() const;

    std::string GetSongFolder() const;

    std::string GetChartPath() const;

    std::string GetMetadataPath() const;

    std::string GetEventsPath() const;

private:

    std::string currentSong;

};
