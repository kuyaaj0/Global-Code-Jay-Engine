#pragma once

class FrameBuffer;
class Texture;

class RenderTexture
{

public:

    RenderTexture();

    bool Create(
        int width,
        int height
    );

    void Begin();

    void End();

    Texture* GetTexture();

private:

    FrameBuffer* framebuffer;

    Texture* texture;

};
