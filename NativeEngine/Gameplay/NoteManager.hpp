#pragma once

#include <vector>

#include "NoteData.hpp"

class Note3D;
class ModifierManager;

class NoteManager
{

public:

    NoteManager();

    ~NoteManager();

    void Update(
        float songPosition,
        ModifierManager* modifiers
    );

    void Render();

    void AddNote(
        Note3D* note
    );

    Note3D* FindClosestNote(
        int lane,
        float songPosition
    );

    void MarkHit(
        Note3D* note
    );

    std::vector<Note3D*>& GetNotes();

private:

    std::vector<Note3D*> notes;

};
