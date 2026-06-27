#pragma once

#include <string>

#include "../Gameplay/StageData.hpp"

class StageLoader
{

public:

    StageLoader();

    StageData LoadStage(
        const std::string& stageName
    );

private:

    std::string FindStageFolder(
        const std::string& stageName
    );

    bool FolderExists(
        const std::string& path
    );

};
