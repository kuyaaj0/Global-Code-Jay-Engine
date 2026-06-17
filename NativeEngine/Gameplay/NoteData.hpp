#pragma once

#include <string>

struct NoteData
{

    float time;

    float sustainLength;

    int lane;

    bool mustHit;

    bool hit;

    bool isHold;

    bool holding;

    bool completed;

    NoteData()
    {
        time = 0.0f;

        sustainLength = 0.0f;

        lane = 0;

        mustHit = true;

        hit = false;

        isHold = false;

        holding = false;

        completed = false;
    }

};
