#pragma once

#include <vector>

class Note3D;
class ModifierManager;

class NoteManager
{

public:

    NoteManager();

    void Update(
        float songPosition,
        ModifierManager* modifiers
    );

    void Render();
    
    NoteData* FindClosestNote(
    int lane,
    float songPosition
);

void MarkHit(
    NoteData* note
);

private:

    std::vector<Note3D*> notes;

};
