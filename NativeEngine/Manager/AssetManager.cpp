#include "AssetManager.hpp"

AssetManager::AssetManager()
{
    modsPath = "Mods/";

    assetsPath = "Assets/";

    defaultsPath = "Engine/Defaults/";
}

bool AssetManager::LoadTexture(
const std::string& name,
const std::string& path)
{
    textures[name] = path;
    return true;
}

bool AssetManager::LoadSound(
const std::string& name,
const std::string& path)
{
    sounds[name] = path;
    return true;
}

bool AssetManager::LoadFont(
const std::string& name,
const std::string& path)
{
    fonts[name] = path;
    return true;
}

bool AssetManager::HasTexture(
const std::string& name) const
{
    return textures.find(name)
        != textures.end();
}

void AssetManager::Clear()
{
    textures.clear();
    sounds.clear();
    fonts.clear();
}
