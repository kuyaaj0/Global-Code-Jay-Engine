#pragma once

#include <string>

#include "../Math/Vector3.hpp"

class Bone
{

public:

    Bone();

    void SetName(
        const std::string& name
    );

    void SetPosition(
        const Vector3& pos
    );

    const std::string& GetName() const;

    Vector3 GetPosition() const;

private:

    std::string boneName;

    Vector3 position;

};
