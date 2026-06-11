#pragma once

#include <string>
#include <unordered_map>

class AssetManager
{

public:

    AssetManager();

    bool LoadTexture(
        const std::string& name,
        const std::string& path
    );

    bool LoadSound(
        const std::string& name,
        const std::string& path
    );

    bool LoadFont(
        const std::string& name,
        const std::string& path
    );

    bool HasTexture(
        const std::string& name
    ) const;

    void Clear();

private:

    std::unordered_map<std::string,std::string> textures;

    std::unordered_map<std::string,std::string> sounds;

    std::unordered_map<std::string,std::string> fonts;

};
