#pragma once

#include <string>
#include <unordered_map>

class SaveManager
{

public:

    SaveManager();

    void SetValue(
        const std::string& key,
        const std::string& value
    );

    std::string GetValue(
        const std::string& key
    ) const;

    bool Save(
        const std::string& path
    );

    bool Load(
        const std::string& path
    );

    void Clear();

private:

    std::unordered_map<std::string,std::string> values;

};
