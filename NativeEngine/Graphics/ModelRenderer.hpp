#pragma once

class Model;
class Camera3D;

class ModelRenderer
{

public:

    ModelRenderer();

    void Draw(
        Model* model,
        Camera3D* camera
    );

};
