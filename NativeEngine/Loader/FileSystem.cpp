#include "FileSystem.hpp"

#include <fstream>
#include <sstream>

bool FileSystem::Exists(
const std::string& path)
{
    std::ifstream file(path);

    return file.good();
}

std::string FileSystem::ReadText(
const std::string& path)
{
    std::ifstream file(path);

    if(!file.is_open())
    {
        return "";
    }

    std::stringstream buffer;

    buffer << file.rdbuf();

    return buffer.str();
}

bool FileSystem::WriteText(
const std::string& path,
const std::string& text)
{
    std::ofstream file(path);

    if(!file.is_open())
    {
        return false;
    }

    file << text;

    return true;
}
