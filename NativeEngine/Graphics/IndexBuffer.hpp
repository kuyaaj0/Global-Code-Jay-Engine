#pragma once

#include <vector>

class IndexBuffer
{

public:

    IndexBuffer();

    void Upload(
        const std::vector<unsigned int>& indices
    );

    void Bind();

    void Unbind();

    unsigned int GetID() const;

private:

    unsigned int id;

};
