#include "SongLoader.hpp"

SongLoader::SongLoader()
{

}

bool SongLoader::Load(
const std::string& song)
{
    currentSong = song;

    return true;
}

std::string SongLoader::GetSongPath() const
{
    return currentSong;
}

std::string SongLoader::GetSongFolder() const
{
    return
        "Assets/BaseGame/Songs/" +
        currentSong +
        "/";
}

std::string SongLoader::GetChartPath() const
{
    return
        GetSongFolder() +
        "chart.json";
}

std::string SongLoader::GetMetadataPath() const
{
    return
        GetSongFolder() +
        "song.json";
}

std::string SongLoader::GetEventsPath() const
{
    return
        GetSongFolder() +
        "events.json";
}
