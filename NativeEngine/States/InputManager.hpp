#pragma once

#include <array>

class InputManager
{

public:

    static const int KEY_COUNT = 8;

    InputManager();

    void Update();

    bool IsPressed(
        int lane
    ) const;

    bool IsJustPressed(
        int lane
    ) const;

    bool IsJustReleased(
        int lane
    ) const;

    void SetState(
        int lane,
        bool value
    );

private:

    std::array<bool, KEY_COUNT> current;

    std::array<bool, KEY_COUNT> previous;

};
