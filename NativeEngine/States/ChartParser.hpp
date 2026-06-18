#pragma once

#include <vector>
#include <string>

#include "../Gameplay/NoteData.hpp"

class ChartParser
{

public:

    ChartParser();

    bool Parse(
        const char* path
    );

    void SetFormat(
        const std::string& value
    );

    std::string GetFormat() const;

    const std::vector<NoteData>&
    GetNotes() const;

private:

    std::vector<NoteData> notes;

    std::string format;

};
