#pragma once

#include "../Gameplay/CharacterData.hpp"

class SongLoader;
class ChartParser;
class Conductor;
class TouchManager;
class AudioManager;
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

    bool LoadWeek(int weekID);

    bool LoadChapter(int chapterID);

    void Update(
    float deltaTime
);

    void Render(
    Renderer* renderer
    );

    void Shutdown();

private:

    CharacterData boyfriend;

    CharacterData dad;

    SongLoader* songLoader;

    ChartParser* chartParser;

    Conductor* conductor;

    TouchManager* touchManager;

    AudioManager* audio;

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
