#include "Bone.hpp"

Bone::Bone()
{
    position = Vector3(0.0f,0.0f,0.0f);
}

void Bone::SetName(
const std::string& name)
{
    boneName = name;
}

void Bone::SetPosition(
const Vector3& pos)
{
    position = pos;
}

const std::string&
Bone::GetName() const
{
    return boneName;
}

Vector3 Bone::GetPosition() const
{
    return position;
}
