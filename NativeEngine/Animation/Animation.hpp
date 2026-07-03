#pragma once

#include <string>
#include <vector>

struct AnimationFrame
{
    int frameIndex;
    float duration;
};

class Animation
{

public:

    Animation();

    void SetName(
        const std::string& name
    );

    void AddFrame(
        int frame,
        float duration
    );

    const std::string& GetName() const;

    const std::vector<AnimationFrame>& GetFrames() const;

    int GetFrameCount() const;

    void Clear();

private:

    std::string animationName;

    std::vector<AnimationFrame> frames;

};
