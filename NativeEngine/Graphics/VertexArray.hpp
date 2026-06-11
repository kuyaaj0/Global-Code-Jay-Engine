#pragma once

class VertexBuffer;
class IndexBuffer;

class VertexArray
{

public:

    VertexArray();

    void AttachVertexBuffer(
        VertexBuffer* buffer
    );

    void AttachIndexBuffer(
        IndexBuffer* buffer
    );

    void Bind();

    void Unbind();

private:

    VertexBuffer* vertexBuffer;

    IndexBuffer* indexBuffer;

};
