#pragma once

#include <string>
#include <unordered_map>

class PreferenceManager
{

public:

    PreferenceManager();

    void Set(
        const std::string& key,
        const std::string& value
    );

    std::string Get(
        const std::string& key
    ) const;

    void Reset();

private:

    std::unordered_map<
        std::string,
        std::string
    > preferences;

};
