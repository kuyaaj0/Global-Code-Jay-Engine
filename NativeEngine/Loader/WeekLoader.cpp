#include "WeekLoader.hpp"

WeekLoader::WeekLoader()
{

}

WeekData WeekLoader::LoadWeek(
const std::string& weekID)
{
    // Future:
    // Check mods/story/<weekID>/week.json
    // If not found:
    // Check assets/story/<weekID>/week.json

    return LoadDefaultWeek(
        weekID
    );
}

WeekData WeekLoader::LoadDefaultWeek(
const std::string& weekID)
{
    WeekData week;

    if(weekID == "chapter1")
    {
        week.weekID = "chapter1";
        week.weekName = "Chapter 1";

        week.songs =
        {
            "Tutorial"
        };

        week.boyfriend = "Boyfriend";
        week.girlfriend = "Girlfriend";
        week.opponent = "Dad";

        week.stage = "Stage";

        week.isJayStory = true;
    }
    else
    if(weekID == "week1")
    {
        week.weekID = "week1";
        week.weekName = "Week 1";

        week.songs =
        {
            "Bopeebo",
            "Fresh",
            "Dad Battle"
        };

        week.boyfriend = "Boyfriend";
        week.girlfriend = "Girlfriend";
        week.opponent = "Dad";

        week.stage = "Stage";

        week.isJayStory = false;
    }

    return week;
}
