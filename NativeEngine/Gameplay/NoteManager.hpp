#pragma once

#include <vector>
#include "Note3D.hpp"

class NoteManager
{
public:

    std::vector<Note3D> notes;

    NoteManager();

    void spawnNote(
        int lane,
        float strumTime
    );

    void update(
        float songPosition
    );

    void clear();
};
