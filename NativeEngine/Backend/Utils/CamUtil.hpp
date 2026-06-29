#pragma once

#include "../../Math/Vector3.hpp"

class CamUtil
{

public:

    // Float interpolation
    static float Lerp(
        float current,
        float target,
        float speed
    );

    // Clamp zoom
    static float ClampZoom(
        float zoom,
        float minZoom,
        float maxZoom
    );

    // Position interpolation
    static Vector3 LerpPosition(
        const Vector3& current,
        const Vector3& target,
        float speed
    );

};
