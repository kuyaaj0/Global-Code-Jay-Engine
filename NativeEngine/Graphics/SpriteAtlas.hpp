#pragma once

#include <string>
#include <unordered_map>
#include <vector>

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

    const std::unordered_map<
    std::string,
    AtlasFrame
    >& GetFrames() const;

    size_t GetFrameCount() const;

    bool ParseLine(
    const std::string& line,
    AtlasFrame& frame
);

    std::string GetAttribute(
    const std::string& line,
    const std::string& attribute
);

    void Clear();

private:

    std::unordered_map<
        std::string,
        AtlasFrame
    > frames;
};
