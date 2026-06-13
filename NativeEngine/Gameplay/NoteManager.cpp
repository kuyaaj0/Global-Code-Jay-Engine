#include "NoteManager.hpp"

#include "Note3D.hpp"

NoteManager::NoteManager()
{

}

void NoteManager::LoadNotes(
const std::vector<NoteData>& chart)
{
    Clear();

    for(const auto& data : chart)
    {
        Note3D* note =
            new Note3D();

        note->SetLane(
            data.lane
        );

        note->SetTime(
            data.time
        );

        notes.push_back(
            note
        );
    }
}

void NoteManager::Update()
{
    for(auto note : notes)
    {
        note->Update();
    }
}

void NoteManager::Render()
{
    for(auto note : notes)
    {
        note->Render();
    }
}

void NoteManager::Clear()
{
    for(auto note : notes)
    {
        delete note;
    }

    notes.clear();
}
