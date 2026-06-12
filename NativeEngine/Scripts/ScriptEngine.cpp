#include "ScriptEngine.hpp"

ScriptEngine::ScriptEngine()
{

}

bool ScriptEngine::LoadScript(
const std::string& path)
{
    scriptPath = path;
    return true;
}

bool ScriptEngine::Execute()
{
    return true;
}

void ScriptEngine::Reset()
{
    scriptPath.clear();
}

ScriptEngine::~ScriptEngine()
{

}
