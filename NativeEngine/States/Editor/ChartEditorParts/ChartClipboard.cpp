#include "ChartClipboard.hpp"

ChartClipboard::ChartClipboard()
{

}

void ChartClipboard::Clear()
{
    clipboard.clear();
}

void ChartClipboard::Copy(
const std::vector<NoteData>& notes)
{
    clipboard = notes;
}

const std::vector<NoteData>&
ChartClipboard::GetClipboard() const
{
    return clipboard;
}
