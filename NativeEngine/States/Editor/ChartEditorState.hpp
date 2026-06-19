#pragma once

class ChartEditorState
{

public:

    ChartEditorState();

    bool Initialize();

    void Update(
        float deltaTime
    );

    void Render();

    void Shutdown();

};
