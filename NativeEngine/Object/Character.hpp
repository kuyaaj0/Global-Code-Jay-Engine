#pragma once

#include "../Transform/Transform.hpp"
#include "../Gameplay/CharacterData.hpp"
#include "../Graphics/Sprite.hpp"
#include "../Animation/Animator.hpp"

class Character
{
public:

    Character();

    void Load(const CharacterData& data);

    Vector3 GetPosition() const;

    void SetPosition(
        const Vector3& position
    );

    Vector3 GetCameraFocus() const;

    const CharacterData& GetData() const;

    void Idle();

    bool IsSinging() const;

    void SetSinging(bool value);

    void SingLeft();

    void SingDown();

    void SingUp();

    void SingRight();

    void Miss();

    void Update(float dt);

    void Render(Renderer* renderer);

public:

    Transform transform;

    float alpha;

    bool visible;

    bool flipX;

    bool flipY;

private:

    Animator animator;

    bool singing;

    float singTimer;

    float singDuration;

    CharacterData characterData;

    Sprite sprite;
};
