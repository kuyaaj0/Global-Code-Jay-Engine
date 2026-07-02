#include "NoteManager.hpp"

#include "../Math/Matrix4.hpp"
#include "../Math/Vector4.hpp"

#include "Note3D.hpp"

#include "../Renderer/Renderer.hpp"

#include "../Modifiers/ModifierManager.hpp"

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

        float width  = note->GetWidth();
        float height = note->GetHeight();

        // -----------------------------
        // BUILD BASE QUAD (NOTE HEAD)
        // -----------------------------
        Matrix4 world =
            Matrix4::Translation(
                position.x,
                position.y,
                position.z
            );

        Vector4 vertices[4];

        vertices[0] = Vector4(-width * 0.5f, -height * 0.5f, 0.0f, 1.0f);
        vertices[1] = Vector4( width * 0.5f, -height * 0.5f, 0.0f, 1.0f);
        vertices[2] = Vector4( width * 0.5f,  height * 0.5f, 0.0f, 1.0f);
        vertices[3] = Vector4(-width * 0.5f,  height * 0.5f, 0.0f, 1.0f);

        // Draw HEAD (always)
        renderer->DrawNote(world, vertices);

        // -----------------------------
        // HOLD NOTE BODY
        // -----------------------------
        if(note->IsHold())
        {
            float sustain = note->GetSustainLength();

            // convert time → screen length
            float bodyLength = sustain * 0.45f;

            // body is BELOW head (extend downward)
            Matrix4 bodyWorld =
                Matrix4::Translation(
                    position.x,
                    position.y - bodyLength * 0.5f,
                    position.z
                ) *
                Matrix4::Scale(
                    1.0f,
                    bodyLength / height,
                    1.0f
                );

            Vector4 body[4];

            body[0] = Vector4(-width * 0.5f, -height * 0.5f, 0.0f, 1.0f);
            body[1] = Vector4( width * 0.5f, -height * 0.5f, 0.0f, 1.0f);
            body[2] = Vector4( width * 0.5f,  height * 0.5f, 0.0f, 1.0f);
            body[3] = Vector4(-width * 0.5f,  height * 0.5f, 0.0f, 1.0f);

            renderer->DrawNote(bodyWorld, body);
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

Note3D* NoteManager::FindClosestPlayerNote(
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

        if(!note->GetData().mustHit)
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

Note3D* NoteManager::FindActiveHold(
int lane
)
{
    for(Note3D* note : notes)
    {
        if(note == nullptr)
            continue;

        if(!note->IsHold())
            continue;

        if(note->GetLane() != lane)
            continue;

        if(note->IsCompleted())
            continue;

        return note;
    }

    return nullptr;
}

void NoteManager::LoadNotes(
const std::vector<NoteData>& chartNotes)
{
    for(Note3D* note : notes)
{
    delete note;
}

notes.clear();
    
    for(const NoteData& data : chartNotes)
    {
        Note3D* note = new Note3D();

        note->SetLane(
            data.lane
        );

        note->SetTime(
            data.time
        );

        if(data.isHold)
        {
            note->SetHold(true);

            note->SetSustainLength(
                data.sustainLength
            );
        }

        AddNote(note);
    }
}

void NoteManager::MarkHit(
Note3D* note)
{
    if(note == nullptr)
        return;

    note->SetHit(true);
}

std::vector<Note3D*> NoteManager::GetOpponentNotes()
{
    std::vector<Note3D*> result;

    for(Note3D* note : notes)
    {
        if(note == nullptr)
            continue;

        if(note->IsPlayerNote())
            continue;

        result.push_back(note);
    }

    return result;
}

std::vector<Note3D*>&
NoteManager::GetNotes()
{
    return notes;
}
