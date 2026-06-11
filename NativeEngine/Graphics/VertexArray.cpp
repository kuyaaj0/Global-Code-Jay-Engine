#include "VertexArray.hpp"

VertexArray::VertexArray()
{
    vertexBuffer = nullptr;
    indexBuffer = nullptr;
}

void VertexArray::AttachVertexBuffer(
VertexBuffer* buffer)
{
    vertexBuffer = buffer;
}

void VertexArray::AttachIndexBuffer(
IndexBuffer* buffer)
{
    indexBuffer = buffer;
}

void VertexArray::Bind()
{

}

void VertexArray::Unbind()
{

}
