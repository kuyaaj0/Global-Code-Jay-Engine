#pragma once

#include "WeekData.hpp"

class WeekLoader
{
public:

    WeekData LoadWeek(int weekID);

    WeekData LoadChapter(int chapterID);
};
