#include "InputManager.hpp"

InputManager::InputManager()
{
    current.fill(false);

    previous.fill(false);
}

void InputManager::Update()
{
    previous = current;
}

bool InputManager::IsPressed(
int lane) const
{
    return current[lane];
}

bool InputManager::IsJustPressed(
int lane) const
{
    return
        current[lane] &&
        !previous[lane];
}

bool InputManager::IsJustReleased(
int lane) const
{
    return
        !current[lane] &&
        previous[lane];
}

void InputManager::SetState(
int lane,
bool value)
{
    current[lane] = value;
}
