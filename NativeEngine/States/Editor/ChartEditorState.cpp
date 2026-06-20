#include "ChartEditorState.hpp"

#include "../../Loader/SongLoader.hpp"
#include "../../States/ChartParser.hpp"
#include "../../Gameplay/NoteManager.hpp"

ChartEditorState::ChartEditorState()
{
    songLoader = nullptr;
    chartParser = nullptr;
    noteManager = nullptr;
}

bool ChartEditorState::Initialize()
{
    grid = new ChartGrid();

    selection = new ChartSelection();

    clipboard = new ChartClipboard();

    sustainTrack = new SustainTrack();
    
    songLoader = new SongLoader();

    chartParser = new ChartParser();

    noteManager = new NoteManager();

    songLoader->Load(
        "Tutorial"
    );

    chartParser->Parse(
        songLoader
        ->GetChartPath()
        .c_str()
    );

    noteManager->LoadNotes(
        chartParser->GetNotes()
    );

    return true;
}

void ChartEditorState::Update(
float deltaTime)
{
    grid->Update();
    sustainTrack->Update();
}

void ChartEditorState::Render(
    Renderer* renderer
);
{
    // Future:
    // Draw grid
    // Draw receptors
    // Draw notes
    grid->Render(renderer);
    sustainTrack->Render(renderer);
}

void ChartEditorState::Shutdown()
{
    delete sustainTrack;

    delete clipboard;

    delete selection;

    delete grid;
    
    delete noteManager;

    delete chartParser;

    delete songLoader;
}
