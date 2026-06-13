#pragma once

#include <vector>

#include "NoteData.hpp"

class Note3D;

class NoteManager
{

public:

    NoteManager();

    void LoadNotes(
        const std::vector<NoteData>& chart
    );

    void Update();

    void Render();

    void Clear();

private:

    std::vector<Note3D*> notes;

};
