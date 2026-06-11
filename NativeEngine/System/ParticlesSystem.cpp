#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem()
{

}

void ParticleSystem::Spawn(
float x,
float y)
{
    Particle p;

    p.x = x;
    p.y = y;
    p.vx = 0.0f;
    p.vy = 0.0f;
    p.life = 1.0f;

    particles.push_back(p);
}

void ParticleSystem::Update(
float dt)
{
    for(auto& p : particles)
    {
        p.x += p.vx * dt;
        p.y += p.vy * dt;
        p.life -= dt;
    }
}

void ParticleSystem::Clear()
{
    particles.clear();
}
