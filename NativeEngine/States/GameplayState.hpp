#pragma once

class SongLoader;
class ChartParser;
class Conductor;
class NoteManager;
class ModifierManager;
class Character;
class Stage;
class HUD;
class ScriptManager;

class GameplayState
{

public:

    GameplayState();

    bool Initialize();

    void LoadSong(
        const char* songName
    );

    void Update();

    void Render();

    void Shutdown();

private:

    SongLoader* songLoader;

    ChartParser* chartParser;

    Conductor* conductor;

    NoteManager* noteManager;

    ModifierManager* modifierManager;

    Character* player;

    Character* opponent;

    Stage* stage;

    HUD* hud;

    ScriptManager* scripts;

};
