#pragma once

#include <string>
#include <vector>

struct GameEvent
{

    float time;

    std::string name;

    std::string value1;

    std::string value2;

    bool executed;

};

class EventSystem
{

public:

    std::vector<GameEvent> events;

    EventSystem();

    void AddEvent(
        const GameEvent& event
    );

    void Update(
        float songPosition
    );

    void Clear();

};
