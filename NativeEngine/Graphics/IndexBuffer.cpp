#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer()
{
    id = 0;
}

void IndexBuffer::Upload(
const std::vector<unsigned int>& indices)
{
    // Future:
    // Upload to GPU

    id = 1;
}

void IndexBuffer::Bind()
{

}

void IndexBuffer::Unbind()
{

}

unsigned int IndexBuffer::GetID() const
{
    return id;
}
