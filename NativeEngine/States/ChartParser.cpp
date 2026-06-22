#include "ChartParser.hpp"
#include <fstream>
#include "Converter/ChartConverter.hpp"
#include "../external/json.hpp"

using json = nlohmann::json;

ChartParser::ChartParser()
{
    format = "native";
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

    if(format == "psych")
{
    return ChartConverter::LoadPsychChart(
        path,
        notes
    );
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

void ChartParser::SetFormat(
const std::string& value)
{
    format = value;
}

std::string ChartParser::GetFormat() const
{
    return format;
}

const std::vector<NoteData>&
ChartParser::GetNotes() const
{
    return notes;
}
