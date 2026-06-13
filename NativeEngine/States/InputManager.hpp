#pragma once

class InputManager
{

public:

    InputManager();

    void Update();

    bool IsLanePressed(
        int lane
    ) const;

};
