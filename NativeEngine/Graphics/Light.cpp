#include "Light.hpp"

Light::Light()
{
    type = Ambient;

    position = Vector3(0.0f,0.0f,0.0f);

    direction = Vector3(0.0f,-1.0f,0.0f);

    intensity = 1.0f;
}

void Light::SetType(Type t)
{
    type = t;
}

void Light::SetPosition(
const Vector3& pos)
{
    position = pos;
}

void Light::SetDirection(
const Vector3& dir)
{
    direction = dir;
}

void Light::SetIntensity(
float value)
{
    intensity = value;
}

Light::Type Light::GetType() const
{
    return type;
}

Vector3 Light::GetPosition() const
{
    return position;
}

Vector3 Light::GetDirection() const
{
    return direction;
}

float Light::GetIntensity() const
{
    return intensity;
}
