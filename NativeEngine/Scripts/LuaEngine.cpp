#include "LuaEngine.hpp"

LuaEngine::LuaEngine()
{
    state = nullptr;
}

bool LuaEngine::Initialize()
{
    // Future:
    // state = luaL_newstate();

    return true;
}

bool LuaEngine::LoadScript(
const std::string& path)
{
    scriptPath = path;

    // Future:
    // luaL_dofile()

    return true;
}

bool LuaEngine::Execute()
{
    // Future:
    // Execute loaded script

    return true;
}

void LuaEngine::Close()
{
    // Future:
    // lua_close(state);

    state = nullptr;
}
