#pragma once

#include <string>

struct NoteSkinData
{
    // Idle notes
    std::string left;
    std::string down;
    std::string up;
    std::string right;

    // Press
    std::string leftPress;
    std::string downPress;
    std::string upPress;
    std::string rightPress;

    // Confirm
    std::string leftConfirm;
    std::string downConfirm;
    std::string upConfirm;
    std::string rightConfirm;

    // Hold body
    std::string holdLeft;
    std::string holdDown;
    std::string holdUp;
    std::string holdRight;

    // Hold end
    std::string holdEndLeft;
    std::string holdEndDown;
    std::string holdEndUp;
    std::string holdEndRight;
};
