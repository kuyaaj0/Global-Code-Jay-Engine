#pragma once

#include <vector>

class Character;

class AnimationSystem
{

public:

    AnimationSystem();

    void AddCharacter(
        Character* character
    );

    void Update(
        float dt
    );

    void Clear();

private:

    std::vector<Character*> characters;

};
