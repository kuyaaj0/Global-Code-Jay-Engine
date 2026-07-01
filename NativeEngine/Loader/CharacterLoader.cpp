#include "CharacterLoader.hpp"

#include "../Object/CharacterParser.hpp"

#include <filesystem>

namespace fs = std::filesystem;

CharacterLoader::CharacterLoader()
{

}

bool CharacterLoader::FolderExists(
const std::string& path)
{
    return fs::exists(path);
}

std::string CharacterLoader::FindCharacterFolder(
const std::string& characterName)
{
    std::string modPath =
        "Mods/Characters/" + characterName;

    if(FolderExists(modPath))
        return modPath;

    std::string assetPath =
        "Assets/Characters/" + characterName;

    if(FolderExists(assetPath))
        return assetPath;

    std::string defaultPath =
        "Engine/Defaults/Characters/" + characterName;

    if(FolderExists(defaultPath))
        return defaultPath;

    return "";
}

CharacterData CharacterLoader::LoadCharacter(
const std::string& characterName)
{
    CharacterData data;

    std::string folder =
        FindCharacterFolder(characterName);

    if(folder.empty())
        return data;

    data.name = characterName;
    data.displayName = characterName;
    data.folder = folder;

    data.spriteAtlas =
        folder + "/sprite.png";

    data.spriteXML =
        folder + "/sprite.xml";

    data.spriteJSON =
        folder + "/sprite.json";

    data.animationFile =
        folder + "/animations.json";

    data.offsetsFile =
        folder + "/offsets.json";

    data.icon =
        folder + "/icon.png";

    return data;

    CharacterParser parser;

    parser.Parse(
    folder,
    data
);
}
