#include "NoteManager.hpp"

#include "Note3D.hpp"

NoteManager::NoteManager()
{

}

void NoteManager::Update(
float songPosition)
{
    for(auto note : notes)
    {
        note->Update(
            songPosition
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
