#include "SpriteBatch.hpp"
#include "Sprite.hpp"

SpriteBatch::SpriteBatch()
{

}

void SpriteBatch::Begin()
{
    sprites.clear();
}

void SpriteBatch::Add(
Sprite* sprite)
{
    sprites.push_back(sprite);
}

void SpriteBatch::End()
{

}

void SpriteBatch::Flush()
{
    for(auto sprite : sprites)
    {
        if(sprite != nullptr)
        {
            sprite->Draw();
        }
    }
}
