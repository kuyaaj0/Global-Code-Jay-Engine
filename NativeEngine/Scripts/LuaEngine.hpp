#pragma once

#include "ScriptEngine.hpp"

struct lua_State;

class LuaEngine : public ScriptEngine
{

public:

    LuaEngine();

    bool Initialize();

    bool LoadScript(
        const std::string& path
    ) override;

    bool Execute() override;

    void Close();

private:

    lua_State* state;

};
