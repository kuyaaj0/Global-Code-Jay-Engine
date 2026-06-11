#include "FrameBuffer.hpp"

FrameBuffer::FrameBuffer()
{
    id = 0;
    width = 0;
    height = 0;
}

bool FrameBuffer::Create(
int w,
int h)
{
    width = w;
    height = h;

    id = 1;

    return true;
}

void FrameBuffer::Bind()
{

}

void FrameBuffer::Unbind()
{

}

void FrameBuffer::Destroy()
{
    id = 0;
}
