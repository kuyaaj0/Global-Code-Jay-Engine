#include "ChartParser.hpp"

ChartParser::ChartParser()
{

}

bool ChartParser::Parse(
const char* path)
{
    notes.clear();

    // Future:
    // Read JSON chart

    NoteData note;

    note.time = 1000.0f;
    note.lane = 0;

    notes.push_back(note);

    note.time = 1250.0f;
    note.lane = 2;

    notes.push_back(note);

    note.time = 1500.0f;
    note.lane = 1;

    notes.push_back(note);

    return true;
}

const std::vector<NoteData>&
ChartParser::GetNotes() const
{
    return notes;
}
