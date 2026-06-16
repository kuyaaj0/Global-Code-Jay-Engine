#include "NoteManager.hpp"

#include "Note3D.hpp"

#include "../Renderer/Renderer.hpp"

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

void NoteManager::Render(
Renderer* renderer)
{
    if(renderer == nullptr)
        return;

    for(Note3D* note : notes)
    {
        if(note == nullptr)
            continue;

        if(note->IsHit())
            continue;

        // Rendering code will go here next
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

        if(note->IsHit())
            continue;

        if(note->GetLane() != lane)
            continue;

        float distance =
            std::fabs(
                note->GetTime() -
                songPosition
            );

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

    note->SetHit(true);
}
