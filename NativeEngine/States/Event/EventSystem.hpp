#pragma once

#include <string>
#include <vector>

struct EventData
{
    float time = 0.0f;

    std::string name;

    std::string value1;

    std::string value2;

    bool executed = false;
};

class EventSystem
{

public:

    std::vector<EventData> events;

    EventSystem();

    void AddEvent(
        const EventData& event
    );

    void Update(
        float songPosition
    );

    void Clear();

};
