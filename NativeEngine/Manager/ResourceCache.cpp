#include "ResourceCache.hpp"

ResourceCache::ResourceCache()
{

}

void ResourceCache::Add(
const std::string& key,
void* resource)
{
    cache[key] = resource;
}

void* ResourceCache::Get(
const std::string& key) const
{
    auto it = cache.find(key);

    if(it == cache.end())
        return nullptr;

    return it->second;
}

bool ResourceCache::Exists(
const std::string& key) const
{
    return cache.find(key)
        != cache.end();
}

void ResourceCache::Clear()
{
    cache.clear();
}
