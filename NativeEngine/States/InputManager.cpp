#include "InputManager.hpp"

InputManager::InputManager()
{
    for(int i = 0; i < 4; i++)
    {
        lanePressed[i] = false;
    }
}

void InputManager::Update()
{
    // Future:
    // Read keyboard
    // Read touch
    // Read gamepad
}

void InputManager::SetLaneState(
    int lane,
    bool pressed
)
{
    if(lane < 0 || lane >= 4)
        return;

    lanePressed[lane] = pressed;
}

bool InputManager::IsLanePressed(
    int lane
) const
{
    if(lane < 0 || lane >= 4)
        return false;

    return lanePressed[lane];
}
