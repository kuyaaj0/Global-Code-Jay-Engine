#pragma once

#include <vector>

#include "Mesh.hpp"

class Material;

class Model
{

public:

    Model();

    void AddMesh(
        const Mesh& mesh
    );

    void SetMaterial(
        Material* material
    );

    void Clear();

private:

    std::vector<Mesh> meshes;

    Material* material;

};
