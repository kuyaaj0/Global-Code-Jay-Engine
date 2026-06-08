#include "NoteManager.hpp"

#include <iostream>

NoteManager::NoteManager()
{
}

void NoteManager::spawnNote(
    int lane,
    float strumTime
)
{
    Note3D note;

    note.lane = lane;
    note.strumTime = strumTime;

    notes.push_back(note);

    std::cout
        << "[NoteManager] Spawned Note"
        << " Lane=" << lane
        << " Time=" << strumTime
        << std::endl;
}

void NoteManager::update(
    float songPosition
)
{
    for(auto& note : notes)
    {
        float distance =
            note.strumTime - songPosition;

        note.position.y =
            distance * 0.45f;
    }
}

void NoteManager::clear()
{
    notes.clear();
}
