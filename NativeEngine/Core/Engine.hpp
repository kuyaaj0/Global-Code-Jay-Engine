#pragma once

class WindowManager;
class Renderer;
class InputManager;
class AudioManager;
class AssetManager;
class ScriptManager;
class GameplayState;

class Engine
{

public:

    Engine();

    bool Initialize();

    void Run();

    void Shutdown();

private:

    WindowManager* window;

    Renderer* renderer;

    InputManager* input;

    AudioManager* audio;

    AssetManager* assets;

    ScriptManager* scripts;

    GameplayState* gameplay;

    bool running;

};
