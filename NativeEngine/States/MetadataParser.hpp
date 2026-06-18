#pragma once

#include "../Loader/SongMetadata.hpp"

class MetadataParser
{

public:

    bool Parse(
        const char* path
    );

    const SongMetadata&
    GetMetadata() const;

private:

    SongMetadata metadata;

};
