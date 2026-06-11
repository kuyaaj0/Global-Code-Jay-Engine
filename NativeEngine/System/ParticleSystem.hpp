#pragma once

#include <vector>

struct Particle
{
    float x;
    float y;
    float vx;
    float vy;
    float life;
};

class ParticleSystem
{

public:

    ParticleSystem();

    void Spawn(
        float x,
        float y
    );

    void Update(
        float dt
    );

    void Clear();

private:

    std::vector<Particle> particles;

};
