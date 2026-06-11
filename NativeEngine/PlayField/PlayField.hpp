#pragma once

#include "../Math/Vector3.hpp"

class PlayField
{

public:

    Vector3 position;

    float laneWidth;

    float receptorY;

    float scrollSpeed;

    bool downscroll;

    bool middlescroll;

    int keyCount;

    PlayField();

    void Reset();

    float GetLaneX(
        int lane
    ) const;

    void Update(
        float dt
    );

};
