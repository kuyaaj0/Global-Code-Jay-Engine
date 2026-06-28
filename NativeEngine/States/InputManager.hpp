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

    // ----------------------
    // Engine Navigation
    // ----------------------

    void SetUpState(bool down);
    void SetDownState(bool down);
    void SetLeftState(bool down);
    void SetRightState(bool down);

    void SetConfirmState(bool down);
    void SetBackState(bool down);
    void SetPauseState(bool down);

    bool IsUpPressed() const;
    bool IsDownPressed() const;
    bool IsLeftPressed() const;
    bool IsRightPressed() const;

    bool IsConfirmPressed() const;
    bool IsBackPressed() const;
    bool IsPausePressed() const;

private:

    bool current[4];
    bool previous[4];

    bool pressed[4];
    bool released[4];

    // Navigation

    bool upCurrent;
    bool upPrevious;
    bool upPressed;

    bool downCurrent;
    bool downPrevious;
    bool downPressed;

    bool leftCurrent;
    bool leftPrevious;
    bool leftPressed;

    bool rightCurrent;
    bool rightPrevious;
    bool rightPressed;

    bool confirmCurrent;
    bool confirmPrevious;
    bool confirmPressed;

    bool backCurrent;
    bool backPrevious;
    bool backPressed;

    bool pauseCurrent;
    bool pausePrevious;
    bool pausePressed;
};
