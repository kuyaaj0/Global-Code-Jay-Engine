#pragma once

class Note3D
{

public:

    Note3D();

    void SetLane(
        int lane
    );

    void SetTime(
        float time
    );

    void Update(
        float currentSongPosition
    );

    void Render();

private:

    int lane;

    float noteTime;

    float yPosition;

};
