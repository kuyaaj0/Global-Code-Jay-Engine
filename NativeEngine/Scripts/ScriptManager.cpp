#include "ScriptManager.hpp"
#include "ScriptEngine.hpp"

ScriptManager::ScriptManager()
{

}

void ScriptManager::AddScript(
std::shared_ptr<ScriptEngine> script)
{
    scripts.push_back(script);
}

void ScriptManager::ExecuteAll()
{
    for(auto& script : scripts)
    {
        if(script)
        {
            script->Execute();
        }
    }
}

void ScriptManager::Clear()
{
    scripts.clear();
}
