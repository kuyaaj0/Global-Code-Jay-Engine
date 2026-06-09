#pragma once

class Matrix4
{

public:

    float m[4][4];

    Matrix4();

    void identity();

    static Matrix4 createIdentity();

};
