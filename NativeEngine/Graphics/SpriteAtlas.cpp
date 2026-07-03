#include "SpriteAtlas.hpp"

#include <fstream>
#include <sstream>

SpriteAtlas::SpriteAtlas()
{
    
}

bool SpriteAtlas::Load(
const std::string& xmlFile)
{
    Clear();

    std::ifstream file(xmlFile);

    if(!file.is_open())
        return false;

    std::string line;

    while(std::getline(file, line))
    {
        AtlasFrame frame;

        if(ParseLine(line, frame))
        {
            frames[frame.name] = frame;
        }
    }

    file.close();

    return true;
}

bool SpriteAtlas::HasFrame(
const std::string& name) const
{
    return
        frames.find(name)
        != frames.end();
}

const AtlasFrame* SpriteAtlas::GetFrame(
const std::string& name) const
{
    auto it =
        frames.find(name);

    if(it == frames.end())
        return nullptr;

    return &it->second;
}

const std::unordered_map<
std::string,
AtlasFrame
>& SpriteAtlas::GetFrames() const
{
    return frames;
}

size_t SpriteAtlas::GetFrameCount() const
{
    return frames.size();
}

std::string SpriteAtlas::GetAttribute(
    const std::string& line,
    const std::string& attribute)
{
    std::string key =
        attribute + "=\"";

    size_t start =
        line.find(key);

    if(start == std::string::npos)
        return "";

    start += key.length();

    size_t end =
        line.find("\"", start);

    if(end == std::string::npos)
        return "";

    return line.substr(
        start,
        end - start
    );
}

bool SpriteAtlas::ParseLine(
const std::string& line,
AtlasFrame& frame)
{
    if(line.find("<SubTexture") == std::string::npos)
        return false;

    frame.name =
        GetAttribute(line, "name");

    frame.x =
        std::stoi(
            GetAttribute(line, "x")
        );

    frame.y =
        std::stoi(
            GetAttribute(line, "y")
        );

    frame.width =
        std::stoi(
            GetAttribute(line, "width")
        );

    frame.height =
        std::stoi(
            GetAttribute(line, "height")
        );

    std::string value;

    value =
        GetAttribute(line, "frameX");

    if(!value.empty())
        frame.frameX = std::stoi(value);

    value =
        GetAttribute(line, "frameY");

    if(!value.empty())
        frame.frameY = std::stoi(value);

    value =
        GetAttribute(line, "frameWidth");

    if(!value.empty())
        frame.frameWidth =
            std::stoi(value);

    value =
        GetAttribute(line, "frameHeight");

    if(!value.empty())
        frame.frameHeight =
            std::stoi(value);

    return true;
}

void SpriteAtlas::Clear()
{
    frames.clear();
}
