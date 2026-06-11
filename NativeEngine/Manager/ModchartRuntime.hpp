#pragma once

#include <string>

class ModchartRuntime
{

public:

    ModchartRuntime();

    bool LoadScript(
        const std::string& path
    );

    void Update(
        float songPosition
    );

    void CallFunction(
        const std::string& name
    );

    void Reset();

};
