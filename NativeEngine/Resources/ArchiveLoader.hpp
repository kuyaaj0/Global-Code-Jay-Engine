#pragma once

#include <string>

class ArchiveLoader
{

public:

    ArchiveLoader();

    bool Open(
        const std::string& path
    );

    bool Extract(
        const std::string& file,
        const std::string& destination
    );

    void Close();

private:

    bool opened;

};
