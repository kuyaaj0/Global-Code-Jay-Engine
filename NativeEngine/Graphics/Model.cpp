#include "Model.hpp"

Model::Model()
{
    material = nullptr;
}

void Model::AddMesh(
const Mesh& mesh)
{
    meshes.push_back(mesh);
}

void Model::SetMaterial(
Material* mat)
{
    material = mat;
}

void Model::Clear()
{
    meshes.clear();
}
