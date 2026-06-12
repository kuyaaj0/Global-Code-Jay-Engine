#pragma once

#include <functional>
#include <string>
#include <vector>

class EventDispatcher
{

public:

    using Callback =
        std::function<void()>;

    EventDispatcher();

    void Register(
        const std::string& name,
        Callback callback
    );

    void Dispatch(
        const std::string& name
    );

    void Clear();

private:

    struct Event
    {
        std::string name;
        Callback callback;
    };

    std::vector<Event> events;

};
