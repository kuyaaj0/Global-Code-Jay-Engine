#pragma once

#include "JudgeResult.hpp"
#include "../Math/Vector3.hpp"

class NoteManager;
class InputManager;
class Renderer;

class StrumLine
{
public:

    StrumLine();

    JudgeResult Judge(
        int lane,
        float songPosition,
        NoteManager* notes
    );

    void Update(InputManager* input);
    void Render(Renderer* renderer);

private:

    Vector3 lanePosition[4];
};
