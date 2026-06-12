#include "ArchiveLoader.hpp"

ArchiveLoader::ArchiveLoader()
{
    opened = false;
}

bool ArchiveLoader::Open(
const std::string& path)
{
    // Future:
    // Open ZIP/PAK/NOVA archive

    opened = true;

    return true;
}

bool ArchiveLoader::Extract(
const std::string& file,
const std::string& destination)
{
    if(!opened)
        return false;

    // Future:
    // Extract file

    return true;
}

void ArchiveLoader::Close()
{
    opened = false;
}
