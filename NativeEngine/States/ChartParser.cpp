#include "ChartParser.hpp"
#include <fstream>
#include "../external/json.hpp"

using json = nlohmann::json;

ChartParser::ChartParser()
{

}

bool ChartParser::Parse(
const char* path)
{
    notes.clear();

    std::ifstream file(path);

    if(!file.is_open())
    {
        return false;
    }

    json chart;
    file >> chart;

    if(!chart.contains("notes"))
    {
        return false;
    }

    for(auto& entry : chart["notes"])
    {
        NoteData note;

        note.time =
            entry.value(
                "time",
                0.0f
            );

        note.lane =
            entry.value(
                "lane",
                0
            );

        note.sustainLength =
            entry.value(
                "sustainLength",
                0.0f
            );

        note.isHold =
            note.sustainLength > 0.0f;

        notes.push_back(note);
    }

    return true;
}

const std::vector<NoteData>&
ChartParser::GetNotes() const
{
    return notes;
}
