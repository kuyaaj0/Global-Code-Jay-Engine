#pragma once

#include <string>
#include <vector>

struct ChartNote
{

    float strumTime;

    int lane;

    bool sustain;

    int player;

};

class ChartParser
{

public:

    std::vector<ChartNote> notes;

    ChartParser();

    bool LoadChart(
        const std::string& path
    );

    void Clear();

    int GetNoteCount() const;

};
