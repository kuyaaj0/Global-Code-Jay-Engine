#include "NoteManager.hpp"

#include "Note3D.hpp"

#include "../Modifier/ModifierManager.hpp"

#include <cmath>

NoteManager::NoteManager()
{

}

NoteManager::~NoteManager()
{
    for(Note3D* note : notes)
    {
        delete note;
    }

    notes.clear();
}

void NoteManager::AddNote(
Note3D* note)
{
    if(note != nullptr)
    {
        notes.push_back(note);
    }
}

void NoteManager::Update(
float songPosition,
ModifierManager* modifiers)
{
    for(Note3D* note : notes)
    {
        if(note != nullptr)
        {
            note->Update(
                songPosition,
                modifiers
            );
        }
    }
}

void NoteManager::Render()
{
    for(Note3D* note : notes)
    {
        if(note != nullptr)
        {
            note->Render();
        }
    }
}

Note3D* NoteManager::FindClosestNote(
int lane,
float songPosition)
{
    Note3D* closest = nullptr;

    float closestDistance = 9999999.0f;

    for(Note3D* note : notes)
    {
        if(note == nullptr)
            continue;

        // We'll compare lane/time later
        // after upgrading Note3D.

        float distance = 0.0f;

        if(distance < closestDistance)
        {
            closestDistance = distance;

            closest = note;
        }
    }

    return closest;
}

void NoteManager::MarkHit(
Note3D* note)
{
    if(note == nullptr)
        return;

    // We'll implement this after
    // adding hit state to Note3D.
}
