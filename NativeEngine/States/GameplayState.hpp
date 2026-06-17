#pragma once


class SongLoader;
class ChartParser;
class Conductor;
class TouchManager;
class NoteManager;
class ModifierManager;
class InputManager;
class StrumLine;
class Renderer;
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

    void Render(
    Renderer* renderer
    );

    void Shutdown();

private:

    SongLoader* songLoader;

    ChartParser* chartParser;

    Conductor* conductor;

    TouchManager* touchManager;

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
