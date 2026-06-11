#include "WindowManager.hpp"

WindowManager::WindowManager()
{
    windowWidth = 1280;

    windowHeight = 720;

    windowTitle = "NativeEngine";
}

void WindowManager::SetTitle(
const std::string& title)
{
    windowTitle = title;
}

void WindowManager::SetSize(
int width,
int height)
{
    windowWidth = width;

    windowHeight = height;
}

int WindowManager::GetWidth() const
{
    return windowWidth;
}

int WindowManager::GetHeight() const
{
    return windowHeight;
}

std::string WindowManager::GetTitle() const
{
    return windowTitle;
}
