#pragma once

#include <vector>

class Note3D;

class NoteManager
{

public:

    NoteManager();

    void Update(
        float songPosition
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
