#pragma once

#include <string>
#include "../Gameplay/SongData.hpp"

class SongMetadata;

class SongLoader
{

public:

    SongLoader();

    bool Load(
        const std::string& song
    );

    SongData GetSongData() const;

    std::string GetSongPath() const;

    std::string GetSongFolder() const;

    std::string GetChartPath(
    const std::string& difficulty
);

    std::string GetInstrumentalPath() const;

    std::string GetVoicesPath() const;

    std::string GetMetadataPath() const;

    std::string GetEventsPath() const;

private:

    std::string currentSong;

};
