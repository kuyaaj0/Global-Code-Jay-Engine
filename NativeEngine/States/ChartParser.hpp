#pragma once

#include <vector>

#include "../Gameplay/NoteData.hpp"

class ChartParser
{

public:

    ChartParser();

    bool Parse(
        const char* path
    );

    const std::vector<NoteData>&
    GetNotes() const;

private:

    std::vector<NoteData> notes;

};
