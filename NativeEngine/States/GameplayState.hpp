#pragma once

#include "../Gameplay/NoteManager.hpp"
#include "../Modifier/ModifierManager.hpp"
#include "../PlayField/PlayField.hpp"
#include "../Gameplay/StrumLine.hpp"
#include "ChartParser.hpp"

#include "../Audio/AudioManager.hpp"
#include "InputManager.hpp"
#include "Event/EventSystem.hpp"

#include "../Renderer/Renderer.hpp"

class GameplayState
{

public:

    GameplayState();

    void Load();

    void Update(
        float dt
    );

    void Render();

    void Reset();

private:

    Renderer renderer;

    AudioManager audio;

    InputManager input;

    EventSystem events;

    ChartParser parser;

    NoteManager noteManager;

    ModifierManager modifierManager;

    PlayField playField;

    StrumLine playerStrums[4];

    StrumLine opponentStrums[4];

};
