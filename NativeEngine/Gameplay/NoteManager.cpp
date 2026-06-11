#include "NoteManager.hpp"

#include "../Renderer/Renderer.hpp"

#include <algorithm>

NoteManager::NoteManager()
{

}

void NoteManager::SpawnNote(
const Note3D& note)
{
    notes.push_back(note);
}

void NoteManager::Update(
float dt)
{
    for(auto& note : notes)
    {
        if(note.alive)
        {
            note.Update(dt);
        }
    }

    RemoveDeadNotes();
}

void NoteManager::Render(
Renderer& renderer)
{
    for(auto& note : notes)
    {
        if(note.visible && note.alive)
        {
            note.Render(renderer);
        }
    }
}

void NoteManager::RemoveDeadNotes()
{
    notes.erase(

        std::remove_if(

            notes.begin(),

            notes.end(),

            [](const Note3D& note)
            {
                return !note.alive;
            }

        ),

        notes.end()

    );
}

void NoteManager::Clear()
{
    notes.clear();
}

int NoteManager::GetNoteCount() const
{
    return static_cast<int>(notes.size());
}
