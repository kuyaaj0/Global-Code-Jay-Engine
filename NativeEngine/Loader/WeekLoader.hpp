#pragma once

#include "../Gameplay/WeekData.hpp"

#include <string>

class WeekLoader
{
public:

    WeekLoader();

    WeekData LoadWeek(
        const std::string& weekID
    );

private:

    WeekData LoadDefaultWeek(
        const std::string& weekID
    );
};
