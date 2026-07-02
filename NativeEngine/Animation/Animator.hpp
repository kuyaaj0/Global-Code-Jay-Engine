#pragma once

#include <string>

class Animation;

class Animator
{

public:

    Animator();

    Animation* GetCurrentAnimation() const;

    void Play(
        Animation* animation
    );

    void Stop();

    void Update(
        float dt
    );

    bool IsPlaying() const;

private:

    Animation* currentAnimation;

    float timer;

    int currentFrame;

    bool loop;

    bool playing;

};
