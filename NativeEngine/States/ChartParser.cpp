#include "ChartParser.hpp"

#include <fstream>

ChartParser::ChartParser()
{

}

bool ChartParser::LoadChart(
const std::string& path)
{
    Clear();

    std::ifstream file(path);

    if(!file.is_open())
    {
        return false;
    }

    // Placeholder:
    // Future JSON parser
    // Example:
    //
    // strumTime
    // lane
    // sustain
    // player

    file.close();

    return true;
}

void ChartParser::Clear()
{
    notes.clear();
}

int ChartParser::GetNoteCount() const
{
    return static_cast<int>(
        notes.size()
    );
}
