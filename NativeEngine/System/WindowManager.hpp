#pragma once

#include <string>

class WindowManager
{

public:

    WindowManager();

    void SetTitle(
        const std::string& title
    );

    void SetSize(
        int width,
        int height
    );

    int GetWidth() const;

    int GetHeight() const;

    std::string GetTitle() const;

private:

    int windowWidth;

    int windowHeight;

    std::string windowTitle;

};
