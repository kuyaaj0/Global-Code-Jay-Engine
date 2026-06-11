#pragma once

#include <vector>

class Sprite;

class SpriteBatch
{

public:

    SpriteBatch();

    void Begin();

    void Add(
        Sprite* sprite
    );

    void End();

    void Flush();

private:

    std::vector<Sprite*> sprites;

};
