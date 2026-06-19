#pragma once

class SongLoader;
class ChartParser;
class NoteManager;

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

    SongLoader* songLoader;

    ChartParser* chartParser;

    NoteManager* noteManager;

};
