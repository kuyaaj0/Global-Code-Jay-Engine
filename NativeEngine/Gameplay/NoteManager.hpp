#pragma once

#include <vector>

class Note3D;

class NoteManager
{

public:

    NoteManager();

    void Update(
        float songPosition
    );

    void Render();

private:

    std::vector<Note3D*> notes;

};
