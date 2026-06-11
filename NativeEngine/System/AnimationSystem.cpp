#include "AnimationSystem.hpp"
#include "../Objects/Character.hpp"

AnimationSystem::AnimationSystem()
{

}

void AnimationSystem::AddCharacter(
Character* character)
{
    characters.push_back(character);
}

void AnimationSystem::Update(
float dt)
{
    for(auto character : characters)
    {
        if(character != nullptr)
        {
            character->Update(dt);
        }
    }
}

void AnimationSystem::Clear()
{
    characters.clear();
}
