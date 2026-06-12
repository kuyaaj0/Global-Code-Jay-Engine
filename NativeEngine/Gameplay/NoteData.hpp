#pragma once

struct NoteData
{

    float time;

    int lane;

    float sustainLength;

    bool mustHit;

    NoteData()
    {
        time = 0.0f;

        lane = 0;

        sustainLength = 0.0f;

        mustHit = true;
    }

};
