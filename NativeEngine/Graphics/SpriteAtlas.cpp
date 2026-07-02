#include "SpriteAtlas.hpp"

SpriteAtlas::SpriteAtlas()
{

}

bool SpriteAtlas::Load(
const std::string& xmlFile)
{
    // XML parser will go here

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

void SpriteAtlas::Clear()
{
    frames.clear();
}
