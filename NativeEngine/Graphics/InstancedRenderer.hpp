#pragma once

#include <vector>

class Model;

class InstancedRenderer
{

public:

    InstancedRenderer();

    void AddInstance(
        Model* model
    );

    void Render();

    void Clear();

private:

    std::vector<Model*> instances;

};
