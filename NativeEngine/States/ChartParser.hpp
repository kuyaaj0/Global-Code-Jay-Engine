#pragma once

#include <vector>

#include "../Gameplay/NoteData.hpp"

enum class ChartFormat
{
    Native,
    Psych,
    Kade,
    Forever,
    Codename
};

class ChartParser
{

public:

    ChartParser();

    bool Parse(
        const char* path
    );

    void SetFormat(
        ChartFormat value
    );

    ChartFormat GetFormat() const;

    const std::vector<NoteData>&
    GetNotes() const;

private:

    std::vector<NoteData> notes;

    ChartFormat format =
        ChartFormat::Native;
};
