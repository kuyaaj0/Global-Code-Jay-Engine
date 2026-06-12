#pragma once

#include "../Math/Vector3.hpp"

class Light
{

public:

    enum Type
    {
        Ambient,
        Directional,
        Point,
        Spot
    };

    Light();

    void SetType(Type t);

    void SetPosition(
        const Vector3& pos
    );

    void SetDirection(
        const Vector3& dir
    );

    void SetIntensity(
        float value
    );

    Type GetType() const;

    Vector3 GetPosition() const;

    Vector3 GetDirection() const;

    float GetIntensity() const;

private:

    Type type;

    Vector3 position;

    Vector3 direction;

    float intensity;

};
