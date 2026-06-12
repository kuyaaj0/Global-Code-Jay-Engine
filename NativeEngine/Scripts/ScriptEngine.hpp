#pragma once

#include <string>

class ScriptEngine
{

public:

    ScriptEngine();

    virtual bool LoadScript(
        const std::string& path
    );

    virtual bool Execute();

    virtual void Reset();

    virtual ~ScriptEngine();

protected:

    std::string scriptPath;

};
