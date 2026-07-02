#include "Animator.hpp"
#include "Animation.hpp"

Animator::Animator()
{
    currentAnimation = nullptr;

    timer = 0.0f;

    currentFrame = 0;

    loop = true;

    playing = false;
}

Animation* Animator::GetCurrentAnimation() const
{
    return currentAnimation;
}

void Animator::Play(
Animation* animation)
{
    currentAnimation = animation;

    timer = 0.0f;

    currentFrame = 0;

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
