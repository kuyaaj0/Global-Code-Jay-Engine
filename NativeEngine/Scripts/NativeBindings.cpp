#include "NativeBindings.hpp"
#include "LuaEngine.hpp"

NativeBindings::NativeBindings()
{

}

void NativeBindings::RegisterAll(
LuaEngine& engine)
{
    RegisterGameplay(engine);
    RegisterGraphics(engine);
    RegisterAudio(engine);
}

void NativeBindings::RegisterGameplay(
LuaEngine& engine)
{
    // Future:
    // setHealth()
    // setScore()
}

void NativeBindings::RegisterGraphics(
LuaEngine& engine)
{
    // Future:
    // cameraShake()
    // setProperty()
}

void NativeBindings::RegisterAudio(
LuaEngine& engine)
{
    // Future:
    // playSound()
    // stopSound()
}
