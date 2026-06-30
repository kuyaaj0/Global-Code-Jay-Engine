#pragma once

#include "../Transform/Transform.hpp"
#include "../Gameplay/CharacterData.hpp"
#include "../Graphics/Sprite.hpp"

class Character
{

public:

    Vector3 GetPosition() const;

    void SetPosition(
        const Vector3& position
    );

    Transform transform;

    float alpha;

    bool visible;

    Vector3 cameraOffset;

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

    void Render(Renderer* renderer);

};
