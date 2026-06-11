#include "ModchartRuntime.hpp"

ModchartRuntime::ModchartRuntime()
{

}

bool ModchartRuntime::LoadScript(
const std::string& path)
{
    return true;
}

void ModchartRuntime::Update(
float songPosition)
{
    // Future:
    // Execute Lua modchart logic
}

void ModchartRuntime::CallFunction(
const std::string& name)
{
    // Future:
    // Call Lua function
}

void ModchartRuntime::Reset()
{

}
