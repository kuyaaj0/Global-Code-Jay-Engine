#pragma once

#include <vector>

#include "../../../Gameplay/NoteData.hpp"

class ChartClipboard
{

public:

    ChartClipboard();

    void Clear();

    void Copy(
        const std::vector<NoteData>& notes
    );

    const std::vector<NoteData>&
    GetClipboard() const;

private:

    std::vector<NoteData> clipboard;

};
