#include "EventSystem.hpp"

EventSystem::EventSystem()
{

}

void EventSystem::AddEvent(
const EventData& event)
{
    events.push_back(event);
}

void EventSystem::Update(
float songPosition)
{
    for(auto& event : events)
    {
        if(event.executed)
            continue;

        if(songPosition >= event.time)
        {
            event.executed = true;

            ExecuteEvent(event);

            // Future:
            // Call Lua
            // Camera Events
            // Character Events
            // Shader Events
        }
    }
}

void EventSystem::Clear()
{
    events.clear();
}
