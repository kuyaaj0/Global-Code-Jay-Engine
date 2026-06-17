#include "TouchManager.hpp"
#include "../States/InputManager.hpp"

TouchManager::TouchManager()
{
}

void TouchManager::Initialize()
{
    receptors.clear();

    for(int i = 0; i < 4; i++)
    {
        TouchReceptor receptor;

        receptor.x = i * 250.0f;
        receptor.y = 600.0f;

        receptor.width = 220.0f;
        receptor.height = 200.0f;

        receptor.lane = i;
        receptor.pressed = false;

        receptors.push_back(receptor);
    }
}

void TouchManager::Update(
InputManager* input)
{
    if(input == nullptr)
        return;

    for(auto& receptor : receptors)
    {
        input->SetLaneState(
            receptor.lane,
            receptor.pressed
        );
    }
}
