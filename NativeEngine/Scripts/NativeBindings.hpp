#pragma once

class LuaEngine;

class NativeBindings
{

public:

    NativeBindings();

    void RegisterAll(
        LuaEngine& engine
    );

    void RegisterGameplay(
        LuaEngine& engine
    );

    void RegisterGraphics(
        LuaEngine& engine
    );

    void RegisterAudio(
        LuaEngine& engine
    );

};
