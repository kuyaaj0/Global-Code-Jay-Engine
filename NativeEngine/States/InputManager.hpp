#pragma once

class InputManager
{

public:

    InputManager();

    void Update();

    void SetLaneState(
        int lane,
        bool pressed
    );

    bool IsLanePressed(
        int lane
    ) const;

private:

    bool lanePressed[4];

};
