#pragma once

#include <string>
#include <unordered_map>

#include "AtlasFrame.hpp"

class SpriteAtlas
{
public:

    SpriteAtlas();

    bool Load(
        const std::string& xmlFile
    );

    bool HasFrame(
        const std::string& name
    ) const;

    const AtlasFrame* GetFrame(
        const std::string& name
    ) const;

    void Clear();

private:

    std::unordered_map<
        std::string,
        AtlasFrame
    > frames;
};
