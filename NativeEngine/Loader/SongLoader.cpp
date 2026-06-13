#include "SongLoader.hpp"

SongLoader::SongLoader()
{

}

bool SongLoader::Load(
const std::string& song)
{
    currentSong = song;

    // Future:
    // Locate song folder
    // Load instrumental
    // Load voices

    return true;
}

std::string SongLoader::GetSongPath() const
{
    return currentSong;
}
