#include "GameplayState.hpp"

#include "../Loader/SongLoader.hpp"
#include "ChartParser.hpp"

#include "../Backend/Conductor.hpp"
#include "..Backend/TouchManager.hpp"
#include "../Gameplay/NoteManager.hpp"
#include "../Gameplay/Note3D.hpp"
#include "../Modifiers/ModifierManager.hpp"

#include "InputManager.hpp"
#include "../Object/StrumLine.hpp"
#include "../Gameplay/ScoreManager.hpp"
#include "../Gameplay/HealthManager.hpp"

#include "../Object/Character.hpp"
#include "Stage/Stage.hpp"

#include "../Hud/HUD.hpp"

#include "../Scripts/ScriptManager.hpp"

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

    touchManager = new TouchManager();

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
    conductor->SetSongPosition(
    audio->GetPlaybackPosition()
);

    touchManager->Update(
    inputManager
);

    inputManager->Update();

    for(int lane = 0; lane < 4; lane++)
{
    if(inputManager->IsLanePressed(lane))
{
    Note3D* note =
        noteManager->FindClosestNote(lane, conductor->GetSongPosition());

    if(note == nullptr)
        continue;

    JudgeResult result =
        strumLine->Judge(
            lane,
            conductor->GetSongPosition(),
            noteManager
        );

    scoreManager->AddJudge(result);
    healthManager->ApplyJudge(result);

    const char* JudgeToString(
JudgeResult result)
{
    switch(result)
    {
        case JudgeResult::Marvelous:
            return "MARVELOUS";

        case JudgeResult::Sick:
            return "SICK";

        case JudgeResult::Good:
            return "GOOD";

        case JudgeResult::Bad:
            return "BAD";

        default:
            return "MISS";
    }
}

    // START HOLD LOGIC
    if(note->IsHold())
    {
        note->SetHit(true);
        note->SetHolding(true);
    }
}
}

    for(auto note : noteManager->GetNotes())
{
    if(note->IsHold() && note->IsHolding())
    {
        if(inputManager->IsLaneHeld(note->GetLane()))
        {
            // still holding → good
        }
        else
        {
            // released early → break hold
            note->SetMissed(true);
        }

        float holdEnd =
            note->GetTime() + note->GetSustainLength();

        if(conductor->GetSongPosition() >= holdEnd)
        {
            note->SetCompleted(true);
        }
    }
}
    
    noteManager->Update(
    conductor->GetSongPosition(),
    modifierManager
);

    for(Note3D* note : noteManager->GetNotes())
{
    if(note == nullptr)
        continue;

    if(note->IsHit())
        continue;

    if(note->IsMissed())
        continue;

    if(
        conductor->GetSongPosition() >
        note->GetTime() + 135.0f
    )
    {
        note->SetMissed(true);

        scoreManager->AddJudge(
            JudgeResult::Miss
        );

        healthManager->ApplyJudge(
            JudgeResult::Miss
        );

        hud->ShowJudgment(
            "MISS"
        );
    }
}

    strumLine->Update(inputManager);

    player->Update();

    opponent->Update();

    stage->Update();

    hud->score =
    scoreManager->GetScore();
    
    hud->combo =
    scoreManager->GetCombo();
    
    hud->misses =
    scoreManager->GetMisses();
    
    hud->accuracy =
    scoreManager->GetAccuracy();
    
    hud->health =
    healthManager->GetHealth();

    hud->ShowJudgment(
    JudgeToString(result)
);

    hud->Update();

    scripts->ExecuteAll();
}

void GameplayState::Render(
Renderer* renderer
)
{
    stage->Render();

    player->Render();

    opponent->Render();

    noteManager->Render(renderer);

    strumLine->Render(renderer);

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

    delete touchManager;

    delete conductor;

    delete chartParser;

    delete songLoader;
}
