#include "PreferenceManager.hpp"

PreferenceManager::PreferenceManager()
{

}

void PreferenceManager::Set(
const std::string& key,
const std::string& value)
{
    preferences[key] = value;
}

std::string PreferenceManager::Get(
const std::string& key) const
{
    auto it = preferences.find(key);

    if(it == preferences.end())
        return "";

    return it->second;
}

void PreferenceManager::Reset()
{
    preferences.clear();
}
