#pragma once

#include "JudgeResult.hpp"

class NoteManager;

class StrumLine
{

public:

    StrumLine();

    JudgeResult Judge(
        int lane,
        float songPosition,
        NoteManager* notes
    );

};
