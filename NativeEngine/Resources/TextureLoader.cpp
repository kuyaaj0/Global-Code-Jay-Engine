#include "TextureLoader.hpp"
#include "../Graphics/Texture.hpp"

TextureLoader::TextureLoader()
{

}

bool TextureLoader::Load(
const std::string& path,
Texture& texture)
{
    return texture.Load(path);
}
