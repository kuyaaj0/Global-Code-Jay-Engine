#pragma once

#include <string>

class Model;

class ModelLoader
{

public:

    ModelLoader();

    bool Load(
        const std::string& path,
        Model& model
    );

};
