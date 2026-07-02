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

    int GetCurrentFrame() const;

    void SetLoop(bool value);

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
