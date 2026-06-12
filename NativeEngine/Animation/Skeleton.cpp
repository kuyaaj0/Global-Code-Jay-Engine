#include "Skeleton.hpp"

Skeleton::Skeleton()
{

}

void Skeleton::AddBone(
const Bone& bone)
{
    bones.push_back(bone);
}

void Skeleton::Clear()
{
    bones.clear();
}

int Skeleton::GetBoneCount() const
{
    return static_cast<int>(
        bones.size()
    );
}
