#include "SceneManager.hpp"

SceneManager::SceneManager()
{
    currentScene = "";
}

void SceneManager::LoadScene(
const std::string& name)
{
    currentScene = name;
}

void SceneManager::ReloadScene()
{
    // Future:
    // Reload current scene
}

void SceneManager::UnloadScene()
{
    currentScene.clear();
}

std::string SceneManager::GetCurrentScene() const
{
    return currentScene;
}
