#include "NoteManager.hpp"

#include "Note3D.hpp"

NoteManager::NoteManager()
{

}

void NoteManager::Update(
float songPosition,
ModifierManager* modifiers)
{
    for(auto note : notes)
    {
        note->Update(
            songPosition,
            modifiers
        );
    }
}

void NoteManager::Render()
{
    for(auto note : notes)
    {
        note->Render();
    }
}

NoteData* FindClosestNote(
    int lane,
    float songPosition
);

void MarkHit(
    NoteData* note
);
