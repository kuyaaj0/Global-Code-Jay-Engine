#pragma once

#include <string>
#include <vector>
#include "SongData.hpp"



struct WeekData
{
    std::string title;

    std::vector<SongData> songs;

    bool isJayStory;
};
