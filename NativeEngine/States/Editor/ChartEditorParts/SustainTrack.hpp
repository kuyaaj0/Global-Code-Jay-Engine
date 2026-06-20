#pragma once

class Renderer;
class Note3D;

class SustainTrack
{

public:

    SustainTrack();

    void Update();

    void Render(
        Renderer* renderer
    );

    void SetCurrentNote(
        Note3D* note
    );

    Note3D* GetCurrentNote() const;

private:

    Note3D* currentNote;

};
