#pragma once

#include <vector>

#include "../Math/Vector3.hpp"

class Mesh
{

public:

    Mesh();

    void AddVertex(
        const Vector3& vertex
    );

    void Clear();

    int GetVertexCount() const;

private:

    std::vector<Vector3> vertices;

};
