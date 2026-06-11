#include "StrumLine.hpp"

#include "../Renderer/Renderer.hpp"

StrumLine::StrumLine()
{
    Reset();
}

void StrumLine::Reset()
{
    transform.Reset();

    lane = 0;

    player = 0;

    pressed = false;

    confirm = false;

    staticState = true;

    alpha = 1.0f;

    angle = 0.0f;
}

void StrumLine::Update(
float dt)
{
    // Future:
    // receptor animations
    // press animation
    // confirm animation
}

void StrumLine::Render(
Renderer& renderer)
{
    // Future:
    // draw receptor sprite
}
