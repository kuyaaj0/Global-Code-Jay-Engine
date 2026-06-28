#pragma once

#include <string>
#include <vector>

struct WeekData
{
    // Display name
    std::string weekName;

    // Songs inside this week
    std::vector<std::string> songs;

    // Characters
    std::string boyfriend;

    std::string girlfriend;

    std::string opponent;

    // Stage
    std::string stage;

    // Difficulty
    int difficulty = 1;

    // Story type
    bool isJayStory = true;
};
