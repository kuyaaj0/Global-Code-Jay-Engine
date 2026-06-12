#include "Animator.hpp"
#include "Animation.hpp"

Animator::Animator()
{
    currentAnimation = nullptr;

    timer = 0.0f;

    playing = false;
}

void Animator::Play(
Animation* animation)
{
    currentAnimation = animation;

    timer = 0.0f;

    playing = true;
}

void Animator::Stop()
{
    playing = false;
}

void Animator::Update(
float dt)
{
    if(!playing || currentAnimation == nullptr)
        return;

    timer += dt;

    // Future:
    // Advance animation frames
}

bool Animator::IsPlaying() const
{
    return playing;
}
