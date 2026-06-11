#pragma once

#include <vector>

#include "Note3D.hpp"

class Renderer;

class NoteManager
{

public:

    std::vector<Note3D> notes;

    NoteManager();

    void SpawnNote(
        const Note3D& note
    );

    void Update(
        float dt
    );

    void Render(
        Renderer& renderer
    );

    void RemoveDeadNotes();

    void Clear();

    int GetNoteCount() const;

};
