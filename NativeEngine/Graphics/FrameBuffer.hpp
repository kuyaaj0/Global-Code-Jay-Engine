#pragma once

class FrameBuffer
{

public:

    FrameBuffer();

    bool Create(
        int width,
        int height
    );

    void Bind();

    void Unbind();

    void Destroy();

private:

    unsigned int id;

    int width;

    int height;

};
