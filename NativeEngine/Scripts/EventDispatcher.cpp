#include "EventDispatcher.hpp"

EventDispatcher::EventDispatcher()
{

}

void EventDispatcher::Register(
const std::string& name,
Callback callback)
{
    events.push_back(
    {
        name,
        callback
    });
}

void EventDispatcher::Dispatch(
const std::string& name)
{
    for(auto& event : events)
    {
        if(event.name == name)
        {
            event.callback();
        }
    }
}

void EventDispatcher::Clear()
{
    events.clear();
}
