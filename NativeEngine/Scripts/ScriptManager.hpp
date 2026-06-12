#pragma once

#include <memory>
#include <vector>

class ScriptEngine;

class ScriptManager
{

public:

    ScriptManager();

    void AddScript(
        std::shared_ptr<ScriptEngine> script
    );

    void ExecuteAll();

    void Clear();

private:

    std::vector<
        std::shared_ptr<ScriptEngine>
    > scripts;

};
