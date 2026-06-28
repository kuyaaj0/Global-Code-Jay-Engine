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

    upCurrent = upPrevious = upPressed = false;

    downCurrent = downPrevious = downPressed = false;

    leftCurrent = leftPrevious = leftPressed = false;

    rightCurrent = rightPrevious = rightPressed = false;

    confirmCurrent = confirmPrevious = confirmPressed = false;

    backCurrent = backPrevious = backPressed = false;

    pauseCurrent = pausePrevious = pausePressed = false;
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

void InputManager::SetUpState(bool down)
{
    upCurrent = down;
}

void InputManager::SetDownState(bool down)
{
    downCurrent = down;
}

void InputManager::SetLeftState(bool down)
{
    leftCurrent = down;
}

void InputManager::SetRightState(bool down)
{
    rightCurrent = down;
}

void InputManager::SetConfirmState(bool down)
{
    confirmCurrent = down;
}

void InputManager::SetBackState(bool down)
{
    backCurrent = down;
}

void InputManager::SetPauseState(bool down)
{
    pauseCurrent = down;
}

//query function to press

bool InputManager::IsUpPressed() const
{
    return upPressed;
}

bool InputManager::IsDownPressed() const
{
    return downPressed;
}

bool InputManager::IsLeftPressed() const
{
    return leftPressed;
}

bool InputManager::IsRightPressed() const
{
    return rightPressed;
}

bool InputManager::IsConfirmPressed() const
{
    return confirmPressed;
}

bool InputManager::IsBackPressed() const
{
    return backPressed;
}

bool InputManager::IsPausePressed() const
{
    return pausePressed;
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

    // Navigation

    upPressed = upCurrent && !upPrevious;
    upPrevious = upCurrent;

    downPressed = downCurrent && !downPrevious;
    downPrevious = downCurrent;

    leftPressed = leftCurrent && !leftPrevious;
    leftPrevious = leftCurrent;

    rightPressed = rightCurrent && !rightPrevious;
    rightPrevious = rightCurrent;

    confirmPressed = confirmCurrent && !confirmPrevious;
    confirmPrevious = confirmCurrent;
    backPressed = backCurrent && !backPrevious;
    backPrevious = backCurrent;

    pausePressed = pauseCurrent && !pausePrevious;
    pausePrevious = pauseCurrent;
}
