#pragma once

#include <vector>

#include "TouchReceptor.hpp"

class InputManager;

class TouchManager
{
public:

    TouchManager();

    void Initialize();

    void Update(
        InputManager* input
    );

private:

    std::vector<TouchReceptor> receptors;
};
