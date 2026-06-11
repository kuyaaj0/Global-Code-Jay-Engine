#pragma once

#include <vector>

struct ReplayFrame
{
    float songPosition;

    bool keys[8];
};

class ReplayManager
{

public:

    ReplayManager();

    void StartRecording();

    void StopRecording();

    void StartPlayback();

    void StopPlayback();

    void AddFrame(
        const ReplayFrame& frame
    );

    void Clear();

    bool IsRecording() const;

    bool IsPlaying() const;

private:

    std::vector<ReplayFrame> replay;

    bool recording;

    bool playing;

};
