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

    timer -= frames[currentFrame].duration;

    currentFrame = 0;

    playing = true;
}

int Animator::GetCurrentFrame() const
{
    return currentFrame;
}

void Animator::SetLoop(bool value)
{
    loop = value;
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

    const auto& frames =
    currentAnimation->GetFrames();

if(frames.empty())
    return;

timer += dt;

if(timer >= frames[currentFrame].duration)
{
    timer = 0.0f;

    currentFrame++;

    if(currentFrame >= static_cast<int>(frames.size()))
    {
        if(loop)
            currentFrame = 0;
        else
        {
            currentFrame =
                frames.size() - 1;

            playing = false;
        }
    }
}

    // Future:
    // Advance animation frames
}

bool Animator::IsPlaying() const
{
    return playing;
}
