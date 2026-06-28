#pragma once

#include <string>

class ChartParser;

class ChartLoader
{
public:

    ChartLoader();

    bool LoadChart(
        const std::string& songName,
        const std::string& difficulty,
        ChartParser& parser
    );

private:

    std::string FindChartPath(
        const std::string& songName,
        const std::string& difficulty
    );
};
