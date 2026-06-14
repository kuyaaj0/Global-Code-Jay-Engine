#pragma once


class SongLoader;
class ChartParser;
class Conductor;
class NoteManager;
class ModifierManager;
class InputManager;
class StrumLine;
class ScoreManager;
class HealthManager;
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

    void Update(
    float deltaTime
);

    void Render();

    void Shutdown();

private:

    SongLoader* songLoader;

    ChartParser* chartParser;

    Conductor* conductor;

    NoteManager* noteManager;

    ModifierManager* modifierManager;

    InputManager* inputManager;

    StrumLine* strumLine;

    ScoreManager* scoreManager;

    HealthManager* healthManager;

    Character* player;

    Character* opponent;

    Stage* stage;

    HUD* hud;

    ScriptManager* scripts;

};
