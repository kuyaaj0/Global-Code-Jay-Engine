#include "CamUtil.hpp"

float CamUtil::Lerp(
float current,
float target,
float speed)
{
    return current +
        (target - current) * speed;
}

float CamUtil::ClampZoom(
float zoom,
float minZoom,
float maxZoom)
{
    if(zoom < minZoom)
        return minZoom;

    if(zoom > maxZoom)
        return maxZoom;

    return zoom;
}

Vector3 CamUtil::LerpPosition(
const Vector3& current,
const Vector3& target,
float speed)
{
    return Vector3(

        Lerp(
            current.x,
            target.x,
            speed
        ),

        Lerp(
            current.y,
            target.y,
            speed
        ),

        Lerp(
            current.z,
            target.z,
            speed
        )

    );
}
