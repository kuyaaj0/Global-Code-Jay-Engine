#include "InputManager.hpp"

InputManager::InputManager()
{
    for(int i = 0; i < 4; i++)
    {
        current[i] = false;
        previous[i] = false;
        pressed[i] = false;
        released[i] = false;
    }
}

void InputManager::SetLaneState(int lane, bool down)
{
    if(lane < 0 || lane >= 4)
        return;

    current[lane] = down;
}

bool InputManager::IsLanePressed(int lane) const
{
    if(lane < 0 || lane >= 4)
        return false;

    return pressed[lane];
}

bool InputManager::IsLaneHeld(int lane) const
{
    if(lane < 0 || lane >= 4)
        return false;

    return current[lane];
}

bool InputManager::IsLaneReleased(int lane) const
{
    if(lane < 0 || lane >= 4)
        return false;

    return released[lane];
}

void InputManager::Update()
{
    for(int i = 0; i < 4; i++)
    {
        // pressed = just went down
        pressed[i] = current[i] && !previous[i];

        // released = just went up
        released[i] = !current[i] && previous[i];

        // save state
        previous[i] = current[i];
    }
}
