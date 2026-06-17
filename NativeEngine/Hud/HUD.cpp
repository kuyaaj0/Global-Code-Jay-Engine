#include "HUD.hpp"

void HUD::Update()
{
    if(judgmentTimer > 0.0f)
    {
        judgmentTimer -= 0.016f;
    }
}

void HUD::ShowJudgment(
const std::string& text)
{
    judgmentText = text;

    judgmentTimer = 1.0f;
}

void HUD::Render()
{
    if(judgmentTimer > 0.0f)
    {
        // Future:
        // Draw judgmentText centered

        // Example:
        // Renderer->DrawText(
        //     judgmentText,
        //     640,
        //     300
        // );
    }
}
