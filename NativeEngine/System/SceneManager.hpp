#pragma once

#include <string>

class SceneManager
{

public:

    SceneManager();

    void LoadScene(
        const std::string& name
    );

    void ReloadScene();

    void UnloadScene();

    std::string GetCurrentScene() const;

private:

    std::string currentScene;

};
