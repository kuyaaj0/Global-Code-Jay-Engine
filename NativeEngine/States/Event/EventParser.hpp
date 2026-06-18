#pragma once

#include <vector>

#include "EventSystem.hpp"

class EventParser
{

public:

    EventParser();

    bool Parse(
        const char* path
    );

    const std::vector<EventData>&
    GetEvents() const;

private:

    std::vector<EventData> events;

};
