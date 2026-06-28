#include "ChartLoader.hpp"

#include "../States/ChartParser.hpp"

#include <fstream>

ChartLoader::ChartLoader()
{

}

bool ChartLoader::LoadChart(
const std::string& songName,
const std::string& difficulty,
ChartParser& parser)
{
    std::string path =
        FindChartPath(
            songName,
            difficulty
        );

    if(path.empty())
        return false;

    return parser.Parse(
        path.c_str()
    );
}

std::string ChartLoader::FindChartPath(
const std::string& songName,
const std::string& difficulty)
{
    // Future search order:
    //
    // mods/songs/<song>/<difficulty>.json
    // assets/songs/<song>/<difficulty>.json

    std::string modPath =
        "mods/songs/" +
        songName +
        "/" +
        difficulty +
        ".json";

    std::ifstream modFile(
        modPath
    );

    if(modFile.good())
        return modPath;

    std::string assetPath =
        "assets/songs/" +
        songName +
        "/" +
        difficulty +
        ".json";

    std::ifstream assetFile(
        assetPath
    );

    if(assetFile.good())
        return assetPath;

    return "";
}
