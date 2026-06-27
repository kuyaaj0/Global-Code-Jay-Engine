#pragma once

#include "../Transform/Transform.hpp"
#include "../Gameplay/CharacterData.hpp"

class Character
{

public:

    Transform transform;

    float alpha;

    bool visible;

    bool flipX;

    bool flipY;

    Character();

    void Load(const CharacterData& data);

    const CharacterData& GetData() const;

    void Idle();

    void SingLeft();

    void SingDown();

    void SingUp();

    void SingRight();

    void Miss();

    void Update(float dt);

    void Render();

};
