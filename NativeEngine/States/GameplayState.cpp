#include "GameplayState.hpp"

#include "../Loader/SongLoader.hpp"
#include "../Loader/ChartParser.hpp"

#include "../Backend/Conductor.hpp"
#include "../Gameplay/NoteManager.hpp"
#include "../Modifier/ModifierManager.hpp"

#include "../Object/Character.hpp"
#include "../Stage/Stage.hpp"

#include "../Hud/HUD.hpp"

#include "../Scripting/ScriptManager.hpp"

GameplayState::GameplayState()
{
    songLoader = nullptr;

    chartParser = nullptr;

    conductor = nullptr;

    noteManager = nullptr;

    modifierManager = nullptr;

    player = nullptr;

    opponent = nullptr;

    stage = nullptr;

    hud = nullptr;

    scripts = nullptr;
}

bool GameplayState::Initialize()
{
    songLoader = new SongLoader();

    chartParser = new ChartParser();

    conductor = new Conductor();

    noteManager = new NoteManager();

    modifierManager = new ModifierManager();

    player = new Character();

    opponent = new Character();

    stage = new Stage();

    hud = new HUD();

    scripts = new ScriptManager();

    return true;
}

void GameplayState::LoadSong(
const char* songName)
{
    songLoader->Load(songName);

    chartParser->Parse(songName);
}

void GameplayState::Update()
{
    conductor->Update();

    noteManager->Update();

    modifierManager->Update();

    player->Update();

    opponent->Update();

    stage->Update();

    hud->Update();

    scripts->ExecuteAll();
}

void GameplayState::Render()
{
    stage->Render();

    player->Render();

    opponent->Render();

    noteManager->Render();

    hud->Render();
}

void GameplayState::Shutdown()
{
    delete scripts;

    delete hud;

    delete stage;

    delete opponent;

    delete player;

    delete modifierManager;

    delete noteManager;

    delete conductor;

    delete chartParser;

    delete songLoader;
}
