#pragma once

class Note3D;

class ChartSelection
{

public:

    ChartSelection();

    void Clear();

    void Select(
        Note3D* note
    );

    Note3D* GetSelected() const;

private:

    Note3D* selectedNote;

};
