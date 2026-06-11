#pragma once

#include "../Math/Vector3.hpp"

class Camera2D
{

public:

    Camera2D();

    void SetPosition(
        const Vector3& pos
    );

    void Move(
        const Vector3& delta
    );

    void SetZoom(
        float value
    );

    Vector3 GetPosition() const;

    float GetZoom() const;

private:

    Vector3 position;

    float zoom;

};
