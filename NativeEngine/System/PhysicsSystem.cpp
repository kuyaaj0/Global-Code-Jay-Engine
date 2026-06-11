#include "PhysicsSystem.hpp"

PhysicsSystem::PhysicsSystem()
{
    gravity = 9.8f;
}

void PhysicsSystem::ApplyGravity(
Vector3& position,
Vector3& velocity,
float dt)
{
    velocity.y -= gravity * dt;

    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
    position.z += velocity.z * dt;
}

void PhysicsSystem::Reset()
{
    gravity = 9.8f;
}
