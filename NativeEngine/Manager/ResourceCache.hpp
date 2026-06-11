#pragma once

#include <string>
#include <unordered_map>

class ResourceCache
{

public:

    ResourceCache();

    void Add(
        const std::string& key,
        void* resource
    );

    void* Get(
        const std::string& key
    ) const;

    bool Exists(
        const std::string& key
    ) const;

    void Clear();

private:

    std::unordered_map<
        std::string,
        void*
    > cache;

};
