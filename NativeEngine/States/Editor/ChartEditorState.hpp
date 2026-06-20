#pragma once

class ChartGrid;
class ChartSelection;
class ChartClipboard;
class SustainTrack;
class SongLoader;
class ChartParser;
class NoteManager;
class Renderer;

class ChartEditorState
{

public:

    ChartEditorState();

    bool Initialize();

    void Update(
        float deltaTime
    );

    void Render();

    void Shutdown();

private:

    ChartGrid* grid;

    ChartSelection* selection;

    ChartClipboard* clipboard;

    SustainTrack* sustainTrack;

    SongLoader* songLoader;

    ChartParser* chartParser;

    NoteManager* noteManager;

    Renderer* renderer;

};
