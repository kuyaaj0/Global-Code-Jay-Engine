#pragma once

#include <vector>

class VertexBuffer
{

public:

    VertexBuffer();

    void Upload(
        const std::vector<float>& vertices
    );

    void Bind();

    void Unbind();

    unsigned int GetID() const;

private:

    unsigned int id;

};
