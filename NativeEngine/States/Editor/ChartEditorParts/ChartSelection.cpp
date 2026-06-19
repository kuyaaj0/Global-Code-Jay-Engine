#include "ChartSelection.hpp"

ChartSelection::ChartSelection()
{
    selectedNote = nullptr;
}

void ChartSelection::Clear()
{
    selectedNote = nullptr;
}

void ChartSelection::Select(
Note3D* note)
{
    selectedNote = note;
}

Note3D*
ChartSelection::GetSelected() const
{
    return selectedNote;
}
