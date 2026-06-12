#pragma once

#include <string>

class PostProcess
{

public:

    PostProcess();

    bool LoadShader(
        const std::string& name
    );

    void Enable();

    void Disable();

    bool IsEnabled() const;

private:

    bool enabled;

};
