#include "EventParser.hpp"

EventParser::EventParser()
{

}

bool EventParser::Parse(
const char* path)
{
    events.clear();

    // JSON parsing later

    return true;
}

const std::vector<EventData>&
EventParser::GetEvents() const
{
    return events;
}
