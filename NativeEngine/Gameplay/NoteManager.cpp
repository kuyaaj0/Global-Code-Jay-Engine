#include "NoteManager.hpp"

#include "../Math/Matrix4.hpp"
#include "../Math/Vector4.hpp"

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
    if(note == nullptr)
        continue;

    if(note->IsHit())
        continue;

   /* const Vector3& position =
        note->GetPosition();

    float width =
        note->GetWidth();

    float height =
        note->GetHeight();*/

    // Rendering code goes here next
    if(
    !note->IsHit() &&
    !note->IsMissed() &&
    songPosition >
    note->GetTime() + 135.0f
)
{
    note->SetMissed(true);
}
}
}

void NoteManager::Render(Renderer* renderer)
{
    if(renderer == nullptr)
        return;

    for(Note3D* note : notes)
    {
        if(note == nullptr)
            continue;

        if(note->IsHit())
            continue;

        if(note->IsMissed())
            continue;

        const Vector3& position = note->GetPosition();

        float width = note->GetWidth();
        float height = note->GetHeight();

     Matrix4 world =
    Matrix4::Translation(
        position.x,
        position.y,
        position.z
    );

    Vector4 vertices[4];

vertices[0] = Vector4(-width * 0.5f, -height * 0.5f, 0, 1);
vertices[1] = Vector4( width * 0.5f, -height * 0.5f, 0, 1);
vertices[2] = Vector4( width * 0.5f,  height * 0.5f, 0, 1);
vertices[3] = Vector4(-width * 0.5f,  height * 0.5f, 0, 1);

    renderer->DrawNote(world, vertices);
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
