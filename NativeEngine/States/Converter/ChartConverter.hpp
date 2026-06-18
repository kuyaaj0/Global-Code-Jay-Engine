#pragma once

#include <vector>
#include <string>

#include "../../Gameplay/NoteData.hpp"

class ChartConverter
{

public:

    static bool LoadPsychChart(
        const std::string& path,
        std::vector<NoteData>& notes
    );

};
