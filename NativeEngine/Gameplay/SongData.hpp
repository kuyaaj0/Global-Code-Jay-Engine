#pragma once

#include <string>
#include <vector>

struct SongData
{
    // Internal ID
    std::string songID;

    // Display name
    std::string songName;

    // Audio
    std::string instrumental;

    std::string voices;

    // Stage used
    std::string stage;

    // Characters
    std::string boyfriend;

    std::string girlfriend;

    std::string opponent;

    // BPM
    float bpm = 120.0f;

    // Scroll speed
    float scrollSpeed = 1.0f;

    // Available difficulties
    std::vector<std::string> difficulties;
};
