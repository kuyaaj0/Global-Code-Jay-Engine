// ChartConverter.hpp

#pragma once

#include <vector>
#include "../../Gameplay/NoteData.hpp"

class ChartConverter
{
public:
    static bool LoadPsychChart(
        const char* path,
        std::vector<NoteData>& notes
    );

    static bool LoadOriginalChart(
        const char* path,
        std::vector<NoteData>& notes
    );
};
