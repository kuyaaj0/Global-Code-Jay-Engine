#include "GameplayState.hpp"

#include "../Loader/SongLoader.hpp"
#include "ChartParser.hpp"

#include "../Backend/Conductor.hpp"
#include "../Gameplay/NoteManager.hpp"
#include "../Gameplay/Note3D.hpp"
#include "../Modifier/ModifierManager.hpp"

#include "InputManager.hpp"
#include "../Object/StrumLine.hpp"
#include "../Gameplay/ScoreManager.hpp"
#include "../Gameplay/HealthManager.hpp"

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

    inputManager = nullptr;
    
    strumLine = nullptr;
    
    scoreManager = nullptr;
    
    healthManager = nullptr;

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

    inputManager = new InputManager();
    
    strumLine = new StrumLine();
    
    scoreManager = new ScoreManager();
    
    healthManager = new HealthManager();

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
    
    const auto& notes =
    chartParser->GetNotes();

for(const auto& noteData : notes)
{
    Note3D* note = new Note3D();

    note->SetLane(
        noteData.lane
    );

    note->SetTime(
        noteData.time
    );

    noteManager->AddNote(
        note
    );
}
}

void GameplayState::Update(
    float deltaTime
)
{
    conductor->Update(
    deltaTime
);

    inputManager->Update();

    for(int lane = 0; lane < 4; lane++)
{
    if(inputManager->IsLanePressed(lane))
    {
        JudgeResult result =
            strumLine->Judge(
                lane,
                conductor->GetSongPosition(),
                noteManager
            );

        scoreManager->AddJudge(result);

        healthManager->ApplyJudge(result);
    }
}
    
    noteManager->Update(
    conductor->GetSongPosition(),
    modifierManager
);

    player->Update();

    opponent->Update();

    stage->Update();

    hud->score =
    scoreManager->GetScore();

    hud->combo =
    scoreManager->GetCombo();

    hud->health =
    healthManager->GetHealth();

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

    delete healthManager;
    
    delete scoreManager;
    
    delete strumLine;
    
    delete inputManager;

    delete noteManager;

    delete conductor;

    delete chartParser;

    delete songLoader;
}
