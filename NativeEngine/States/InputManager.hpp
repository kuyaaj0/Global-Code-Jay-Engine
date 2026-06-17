#pragma once

class InputManager
{
public:

    InputManager();

    void Update();

    // Lane control (from backend input system)
    void SetLaneState(int lane, bool down);

    // Queries
    bool IsLanePressed(int lane) const;   // just pressed this frame
    bool IsLaneHeld(int lane) const;      // currently held
    bool IsLaneReleased(int lane) const;  // just released

private:

    bool current[4];
    bool previous[4];

    bool pressed[4];
    bool released[4];
};
