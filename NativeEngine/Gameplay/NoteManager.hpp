#pragma once

#include <vector>

#include "NoteData.hpp"

class Note3D;
class ModifierManager;
class Renderer;

class NoteManager
{

public:

    NoteManager();

    ~NoteManager();

    void Update(
        float songPosition,
        ModifierManager* modifiers
    );

    void Render(
    Renderer* renderer
);

    void AddNote(
        Note3D* note
    );

    Note3D* FindClosestNote(
        int lane,
        float songPosition
    );

    Note3D* FindActiveHold(
    int lane
);

    void LoadNotes(
    const std::vector<NoteData>& chartNotes
);

    void MarkHit(
        Note3D* note
    );

    std::vector<Note3D*>& GetNotes();

private:

    std::vector<Note3D*> notes;

};
