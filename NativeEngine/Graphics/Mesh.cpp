#include "Mesh.hpp"

Mesh::Mesh()
{

}

void Mesh::AddVertex(
const Vector3& vertex)
{
    vertices.push_back(vertex);
}

void Mesh::Clear()
{
    vertices.clear();
}

int Mesh::GetVertexCount() const
{
    return static_cast<int>(
        vertices.size()
    );
}
