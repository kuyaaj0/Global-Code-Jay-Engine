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

}

void ChartEditorState::Render()
{
    // Future:
    // Draw grid
    // Draw receptors
    // Draw notes
}

void ChartEditorState::Shutdown()
{
    delete noteManager;

    delete chartParser;

    delete songLoader;
}
