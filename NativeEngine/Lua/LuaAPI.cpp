#include "LuaAPI.hpp"

bool LuaAPI::LoadScript(
const std::string& path)
{
    // Future:
    // luaL_dofile()

    return true;
}

void LuaAPI::Call(
const std::string& function)
{
    // Future:
    // lua_getglobal()
    // lua_pcall()
}

void LuaAPI::SetGlobal(
const std::string& name,
double value)
{
    // Future:
    // lua_pushnumber()
}

double LuaAPI::GetGlobal(
const std::string& name)
{
    // Future:
    // lua_getglobal()

    return 0.0;
}
