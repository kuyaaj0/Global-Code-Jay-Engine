#include "WeekLoader.hpp"

WeekData WeekLoader::LoadWeek(int weekID)
{
    WeekData week;

    switch(weekID)
    {
        case 0:

            week.title = "Week 1";

            week.songs =
            {
                "Bopeebo",
                "Fresh",
                "Dad Battle"
            };

            week.isJayStory = false;

            break;
    }

    return week;
}

WeekData WeekLoader::LoadChapter(int chapterID)
{
    WeekData chapter;

    switch(chapterID)
    {
        case 0:

            chapter.title = "Chapter 1";

            chapter.songs =
            {
                "Tutorial",
                "UnknownSong",
                "BossSong"
            };

            chapter.isJayStory = true;

            break;
    }

    return chapter;
}
