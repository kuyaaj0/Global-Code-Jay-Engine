#include "StageLoader.hpp"

#include <filesystem>

namespace fs = std::filesystem;

StageLoader::StageLoader()
{

}

bool StageLoader::FolderExists(
const std::string& path)
{
    return fs::exists(path);
}

std::string StageLoader::FindStageFolder(
const std::string& stageName)
{
    std::string modPath =
        "Mods/Stages/" + stageName;

    if(FolderExists(modPath))
        return modPath;

    std::string assetPath =
        "Assets/Stages/" + stageName;

    if(FolderExists(assetPath))
        return assetPath;

    std::string defaultPath =
        "Engine/Defaults/Stages/" + stageName;

    if(FolderExists(defaultPath))
        return defaultPath;

    return "";
}

StageData StageLoader::LoadStage(
const std::string& stageName)
{
    StageData data;

    std::string folder =
        FindStageFolder(stageName);

    if(folder.empty())
        return data;

    data.name = stageName;
    data.displayName = stageName;
    data.folder = folder;

    data.background =
        folder + "/background.png";

    data.foreground =
        folder + "/foreground.png";

    data.props =
        folder + "/props.png";

    data.defaultCameraZoom = 1.0f;

    return data;
}
