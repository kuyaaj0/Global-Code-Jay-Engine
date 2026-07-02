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

    bool HasSound(
    const std::string& name
    ) const;

    bool HasFont(
    const std::string& name
    ) const;

    void Clear();

    std::string FindTexture(
    const std::string& name
);
    std::string FindSound(
    const std::string& name
);

    std::string FindFont(
    const std::string& name
);

    std::string FindCharacter(
    const std::string& characterName
);

    std::string FindStage(
    const std::string& stageName
);

    std::string FindSong(
    const std::string& songName
);

private:

    std::unordered_map<std::string,std::string> textures;

    std::unordered_map<std::string,std::string> sounds;

    std::unordered_map<std::string,std::string> fonts;

    std::string modsPath;

    std::string assetsPath;

    std::string defaultsPath;

};
