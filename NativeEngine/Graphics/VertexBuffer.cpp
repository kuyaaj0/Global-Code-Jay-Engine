#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer()
{
    id = 0;
}

void VertexBuffer::Upload(
const std::vector<float>& vertices)
{
    // Future:
    // Upload to GPU

    id = 1;
}

void VertexBuffer::Bind()
{

}

void VertexBuffer::Unbind()
{

}

unsigned int VertexBuffer::GetID() const
{
    return id;
}
