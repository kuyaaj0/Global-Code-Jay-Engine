#pragma once

#include <vector>

#include "Bone.hpp"

class Skeleton
{

public:

    Skeleton();

    void AddBone(
        const Bone& bone
    );

    void Clear();

    int GetBoneCount() const;

private:

    std::vector<Bone> bones;

};
