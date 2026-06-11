#include "SaveManager.hpp"

#include <fstream>

SaveManager::SaveManager()
{

}

void SaveManager::SetValue(
const std::string& key,
const std::string& value)
{
    values[key] = value;
}

std::string SaveManager::GetValue(
const std::string& key) const
{
    auto it = values.find(key);

    if(it == values.end())
        return "";

    return it->second;
}

bool SaveManager::Save(
const std::string& path)
{
    std::ofstream file(path);

    if(!file.is_open())
        return false;

    for(const auto& pair : values)
    {
        file
            << pair.first
            << "="
            << pair.second
            << "\n";
    }

    file.close();

    return true;
}

bool SaveManager::Load(
const std::string& path)
{
    // Future:
    // Read key=value pairs

    return true;
}

void SaveManager::Clear()
{
    values.clear();
}
