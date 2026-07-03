#include "Animation.hpp"

Animation::Animation()
{

}

void Animation::SetName(
const std::string& name)
{
    animationName = name;
}

void Animation::AddFrame(
int frame,
float duration)
{
    AnimationFrame f;

    f.frameIndex = frame;
    f.duration = duration;

    frames.push_back(f);
}

const std::string& Animation::GetName() const
{
    return animationName;
}

const std::vector<AnimationFrame>&
Animation::GetFrames() const
{
    return frames;
}

int Animation::GetFrameCount() const
{
    return static_cast<int>(frames.size());
}

void Animation::Clear()
{
    frames.clear();
}
