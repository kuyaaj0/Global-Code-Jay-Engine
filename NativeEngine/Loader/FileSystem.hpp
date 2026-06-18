#pragma once

#include <string>

class FileSystem
{

public:

    static bool Exists(
        const std::string& path
    );

    static std::string ReadText(
        const std::string& path
    );

    static bool WriteText(
        const std::string& path,
        const std::string& text
    );

};
