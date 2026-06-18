#include "ChartConverter.hpp"

#include <fstream>

#include "../external/json.hpp"

using json = nlohmann::json;

bool ChartConverter::LoadPsychChart(
const std::string& path,
std::vector<NoteData>& notes)
{
    notes.clear();

    std::ifstream file(path);

    if(!file.is_open())
    {
        return false;
    }

    json root;

    file >> root;

    // Actual Psych parsing later

    return true;
}
