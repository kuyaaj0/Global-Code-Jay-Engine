#include "SustainTrack.hpp"

#include "../../../Gameplay/Note3D.hpp"
#include "../../../Renderer/Renderer.hpp"

SustainTrack::SustainTrack()
{
    currentNote = nullptr;
}

void SustainTrack::Update()
{

}

void SustainTrack::Render(
Renderer* renderer)
{
    if(renderer == nullptr)
        return;

    if(currentNote == nullptr)
        return;

    // Future:
    // Draw sustain preview
    // Draw sustain handles
}

void SustainTrack::SetCurrentNote(
Note3D* note)
{
    currentNote = note;
}

Note3D*
SustainTrack::GetCurrentNote() const
{
    return currentNote;
}
