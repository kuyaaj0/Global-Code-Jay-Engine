#include "GameplayState.hpp"

#include "../Loader/SongLoader.hpp"
#include "../Loader/CharacterLoader.hpp"
#include "ChartParser.hpp"

#include "../Backend/Conductor.hpp"
#include "../Backend/TouchManager.hpp"
#include "../Audio/AudioManager.hpp"
#include "../Gameplay/JudgeResult.hpp"
#include "../Gameplay/NoteManager.hpp"
#include "../Gameplay/Note3D.hpp"
#include "../Gameplay/NoteData.hpp"
#include "../Modifiers/ModifierManager.hpp"

#include "InputManager.hpp"
#include "../Object/StrumLine.hpp"
#include "../Gameplay/ScoreManager.hpp"
#include "../Gameplay/HealthManager.hpp"

#include "../Object/Character.hpp"
#include "Stage/Stage.hpp"

#include "../Hud/HUD.hpp"

#include "../Scripts/ScriptManager.hpp"

const char* JudgeToString(
    JudgeResult result
);

GameplayState::GameplayState()
{
    songLoader = nullptr;

    chartParser = nullptr;

    conductor = nullptr;

    touchManager = nullptr;
    
    audio = nullptr;

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
    touchManager->Initialize();
    
    audio = new AudioManager();

    noteManager = new NoteManager();

    modifierManager = new ModifierManager();

    inputManager = new InputManager();
    
    strumLine = new StrumLine();
    
    scoreManager = new ScoreManager();
    
    healthManager = new HealthManager();

    player = new Character();

    opponent = new Character();

    CharacterLoader loader;

    boyfriend = loader.LoadCharacter("Boyfriend");

    dad = loader.LoadCharacter("Dad");

    player->Load(boyfriend);
    opponent->Load(dad);

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

    note->SetHold(
    noteData.isHold
);
    
    note->SetSustainLength(
    noteData.sustainLength
);

    noteManager->AddNote(
        note
    );
}
}

bool GameplayState::LoadWeek(int weekID)
{
    // Load vanilla songs

    return true;
}

bool GameplayState::LoadChapter(int chapterID)
{
    // Load Jay Engine campaign

    return true;
}

void GameplayState::Update(
    float deltaTime
)
{
    conductor->SetSongPosition(
    audio->GetPlaybackPosition()
);

    JudgeResult lastJudge =
    JudgeResult::Miss;
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

    lastJudge =
    strumLine->Judge(
        lane,
        conductor->GetSongPosition(),
        noteManager
    );

scoreManager->AddJudge(lastJudge);
healthManager->ApplyJudge(lastJudge);

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

    player->Update(deltaTime);

    opponent->Update(deltaTime);

    stage->Update(deltaTime);

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
    JudgeToString(lastJudge)
);

    hud->Update();

    scripts->ExecuteAll();
}

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

void GameplayState::Render(
Renderer* renderer
)
{
    stage->Render(renderer);

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
    
    delete audio;

    delete touchManager;

    delete conductor;

    delete chartParser;

    delete songLoader;
}
